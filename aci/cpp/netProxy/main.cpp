/*
 * main.cpp
 * 
 * This file is part of the IHMC NetProxy Library/Component
 * Copyright (c) 2010-2014 IHMC.
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 3 (GPLv3) as published by the Free Software Foundation.
 * 
 * U.S. Government agencies and organizations may redistribute
 * and/or modify this program under terms equivalent to
 * "Government Purpose Rights" as defined by DFARS
 * 252.227-7014(a)(12) (February 2014).
 * 
 * Alternative licenses that allow for use within commercial products may be
 * available. Contact Niranjan Suri at IHMC (nsuri@ihmc.us) for details.
 *
 * NetProxy is a proxy for the components of the IHMC Agile Computing Middleware (ACM)
 * 
 * NetProxy transparently interfaces with legacy applications by using packet
 * capture / injection mechanisms and then uses ACM components such as
 * DisService or Mockets to perform the actual data communications.
 */

#include <stdio.h>
#include <csignal>
#if defined (WIN32)
    #include <iostream>
    #include <winsock2.h>
    #include <windows.h>
#elif defined (UNIX)
    #include <sys/socket.h>
    #include <netinet/in.h>
    #define stricmp strcasecmp
    #define FOREVER 0xFFFFFFFFU
#endif

#include "NLFLib.h"
#include "InetAddr.h"
#include "StrClass.h"
#include "Logger.h"

#include "Utilities.h"
#include "TapInterface.h"
#include "PCapInterface.h"
#include "NetProxyConfigManager.h"
#include "PacketRouter.h"

#if defined (UNIX)
    #define stricmp strcasecmp
    #define FOREVER 0xFFFFFFFFU
#endif


using namespace NOMADSUtil;

#define checkAndLogMsg if (pLogger) pLogger->logMsg

namespace ACMNetProxy
{
    #if defined (WIN32)
        void abortExecution (int param)
        {
            checkAndLogMsg ("abortExecution", Logger::L_MildError,
                            "execution aborted!\n");
            exit (-1);
        }
        
    #elif defined (UNIX)
        void abortExecution (int sig, siginfo_t *siginfo, void *context)
        {
            checkAndLogMsg ("abortExecution", Logger::L_MildError,
                            "execution aborted!\n");
            exit (-1);
        }
    #endif

    void terminateExecution (int param)
    {
        #if defined (WIN32)
            // installing abortExecution handler
            if (signal (SIGINT, abortExecution) == SIG_ERR) {
                checkAndLogMsg ("terminateExecution", Logger::L_SevereError,
                                "impossible to install abort handler! Exiting now...\n");
                exit (-2);
            }
            if (signal (SIGTERM, abortExecution) == SIG_ERR) {
                checkAndLogMsg ("terminateExecution", Logger::L_SevereError,
                                "impossible to install abort handler! Exiting now...\n");
                exit (-3);
            }
            if (signal (SIGBREAK, abortExecution) == SIG_ERR) {
                checkAndLogMsg ("terminateExecution", Logger::L_SevereError,
                                "impossible to install abort handler! Exiting now...\n");
                exit (-4);
            }
        #elif defined (UNIX)
            struct sigaction actInt, actTerm;
	        memset (&actInt, '\0', sizeof (actInt));
	        memset (&actTerm, '\0', sizeof (actTerm));
 
	        /* Use the sa_sigaction field because the handles has two additional parameters */
	        actInt.sa_sigaction = &abortExecution;
	        actTerm.sa_sigaction = &abortExecution;
 
	        /* The SA_SIGINFO flag tells sigaction() to use the sa_sigaction field, not sa_handler. */
	        actInt.sa_flags = SA_SIGINFO;
	        actTerm.sa_flags = SA_SIGINFO;
 
	        if (sigaction (SIGINT, &actInt, NULL) < 0) {
                checkAndLogMsg ("terminateExecution", Logger::L_SevereError,
                                "impossible to install abort handler for SIGINT! Exiting now...\n");
                exit (-2);
	        }
 
	        if (sigaction (SIGTERM, &actTerm, NULL) < 0) {
                checkAndLogMsg ("terminateExecution", Logger::L_SevereError,
                                "impossible to install abort handler for SIGTERM! Exiting now...\n");
                exit (-3);
	        }
        #endif

        checkAndLogMsg ("terminateExecution", Logger::L_Info,
                        "exit requested by user! Terminating execution...\n");
        PacketRouter::requestTermination();

        #if defined (WIN32)
        sleepForMilliseconds (2000);
        #endif
    }
}

int main (int argc, char *argv[])
{
    int rc;
    pLogger = new Logger();
    pLogger->enableScreenOutput();      // any errors occurring before reading configuration file are logged to screen
    pLogger->setDebugLevel (Logger::L_Info);

    const char * const pszDefaultConfigFileName = "netproxy.cfg";
    // Check to see if a config file path was specified on the command-line
    String homeDir;
    String configFilePath;

    int i = 1;
    while (i < argc) {
        #if defined (WIN32)
            if (0 == stricmp (argv[i], "-testtap")) {
                ACMNetProxy::TapInterface *pTI = ACMNetProxy::TapInterface::getTAPInterface();

                // TODO: Fix uninitialized rc variable
                switch (rc) {
                case 0:
                    if (pTI->checkMACAddress()) {
                        checkAndLogMsg ("TAP INTERFACE TEST - ", Logger::L_Info, "SUCCESSFULLY RUN\n");
                        return 0;
                    }
                    else {
                        checkAndLogMsg ("TAP INTERFACE TEST - ", Logger::L_MildError, "THE IP ADDRESS DOES NOT MATCH THE MAC ADDRESS\n");
                        return -4;
                    }
                case -1:
                    checkAndLogMsg ("TAP INTERFACE TEST - ", Logger::L_MildError, "NO TAP-WIN32 INTERFACE FOUND\n");
                    return -5;
                case -2:
                    checkAndLogMsg ("TAP INTERFACE TEST - ", Logger::L_MildError, "FOUND MORE THAN ONE TAP INTERFACE: DO NOT KNOW WHICH ONE TO USE\n");
                    return -6;
                case -3:
                    checkAndLogMsg ("TAP INTERFACE TEST - ", Logger::L_MildError, "FAILED OPENING THE TAP INTERFACE DEVICE\n");
                    return -7;
                case -4:
                    checkAndLogMsg ("TAP INTERFACE TEST - ", Logger::L_MildError, "FAILED CREATING THE READING EVENT\n");
                    return -8;
                case -5:
                    checkAndLogMsg ("TAP INTERFACE TEST - ", Logger::L_MildError, "FAILED CREATING THE WRITING EVENT\n");
                    return -9;
                default:
                    checkAndLogMsg ("TAP INTERFACE TEST - ", Logger::L_MildError, "UNKNOWN ERROR\n");
                    return -10;
                }
            }
        #endif

        if (0 == stricmp (argv[i], "-conf")) {
            i++;
            if (i < argc) {
                checkAndLogMsg ("main", Logger::L_Info,
                                "setting config file path to %s\n", argv[i]);
                configFilePath = argv[i];
            }
        }
        i++;
    }

    if (configFilePath.length() <= 0) {
        // Nothing was specified on the command-line
        // Try to determine the path to the config file
        const char *pszProgDir = getProgHomeDir (argv[0]);
        if (pszProgDir == NULL) {
            checkAndLogMsg ("main", Logger::L_MildError,
                            "unable to determine the home directory for the executable\n");
            // Simply try to open the default config file name in the current directory
            configFilePath = pszDefaultConfigFileName;
            checkAndLogMsg ("main", Logger::L_Info,
                            "will attempt to open the config file %s\n", (const char*) configFilePath);
        }
        else {
            // Compute the Home Directory
            // Assume that the executable is in <home>\\bin (or <home/bin>)
            char szHomeDir[PATH_MAX];
            strcpy (szHomeDir, pszProgDir);
            // Strip off last directory level in path
            char *pszTemp = strrchr (szHomeDir, getPathSepChar());
            if (pszTemp == NULL) {
                checkAndLogMsg ("main", Logger::L_SevereError,
                                "executable not installed in expected directory structure - could not parse directory "
                                "<%s> to compute the config file directory\n", pszProgDir);
                return -2;
            }
            *pszTemp = '\0';
            homeDir = szHomeDir;
            configFilePath = szHomeDir;
            configFilePath += getPathSepCharAsString();
            configFilePath += "conf";
            configFilePath += getPathSepCharAsString();
            configFilePath += pszDefaultConfigFileName;
            checkAndLogMsg ("main", Logger::L_Info,
                            "using %s as path for the config files\n", (const char*) configFilePath);
        }
    }

    ACMNetProxy::NetProxyConfigManager *pCfgManager = ACMNetProxy::NetProxyConfigManager::getNetProxyConfigManager();
    // Read the config file
    if (0 != (rc = pCfgManager->init (homeDir, configFilePath))) {
        checkAndLogMsg ("main", Logger::L_MildError,
                        "failed to call init() on ConfigurationManager with config file path <%s>; rc = %d\n",
                        (const char*) configFilePath, rc);
        return -3;
    }

    if (0 != (rc = pCfgManager->processConfigFiles())) {
        checkAndLogMsg ("main", Logger::L_SevereError,
                        "config files processing failed with rc = %d\n", rc);
        return -4;
    }

    // Address parameter or device name specified via command line overwrites the one specified in the config file
    i = 1;
    String deviceName;
    InetAddr configuredIPv4Addr, configuredNetmask, configuredGateway;
    uint16 ui16ConfiguredMTU = 0;
    while (i < argc) {
        if ((0 == stricmp (argv[i], "-addr")) || (0 == stricmp (argv[i], "-address"))) {
            i++;
            if (i < argc) {
                checkAndLogMsg ("main", Logger::L_Info,
                                "setting IP address for Tap Interface to be <%s>\n", argv[i]);
                pCfgManager->setValue ("IPAddress", argv[i]);
            }
        }
        else if ((0 == stricmp (argv[i], "-device")) || (0 == stricmp (argv[i], "-interface"))) {
            i++;
            if (i < argc) {
                checkAndLogMsg ("main", Logger::L_Info,
                                "setting device/interface for PCap to be <%s>\n", argv[i]);
                pCfgManager->setValue ("DeviceName", argv[i]);
            }
        }
        i++;
    }
    if (pCfgManager->hasValue ("IPAddress")) {
        configuredIPv4Addr = InetAddr (pCfgManager->getValue ("IPAddress"));
    }
    if (pCfgManager->hasValue ("Netmask")) {
        configuredNetmask = InetAddr (pCfgManager->getValue ("Netmask"));
    }
    if (pCfgManager->hasValue ("GatewayAddress")) {
        configuredGateway = InetAddr (pCfgManager->getValue ("GatewayAddress"));
    }
    if (pCfgManager->hasValue ("TAPInterfaceMTU")) {
        ui16ConfiguredMTU = (uint16) atoi(pCfgManager->getValue ("TAPInterfaceMTU"));
    }

    // Instantiate the appropriate NetworkInterface, based on the NetProxy mode
    ACMNetProxy::NetworkInterface *pInternalNetworkInterface = NULL, *pExternalNetworkInterface = NULL;
    if (ACMNetProxy::NetProxyApplicationParameters::GATEWAY_MODE) {
        // Running in Gateway mode: use PCap library and retrieve MAC addresses of the external interface
        const char * const pszInternalInterfaceName = pCfgManager->getValue ("InternalInterfaceName");
        if (pszInternalInterfaceName == NULL) {
            checkAndLogMsg ("main", Logger::L_SevereError,
                            "internal interface to use for gateway mode has not been specified\n");
            return -5;
        }
        const char *pszExternalInterfaceName = pCfgManager->getValue ("ExternalInterfaceName");
        if (pszExternalInterfaceName == NULL) {
            checkAndLogMsg ("main", Logger::L_SevereError,
                            "external interface to use for gateway mode has not been specified\n");
            return -5;
        }
        if (NULL == (pInternalNetworkInterface = ACMNetProxy::PCapInterface::getPCapInterface (pszInternalInterfaceName))) {
            checkAndLogMsg ("main", Logger::L_SevereError,
                            "could not open device <%s>\n", pInternalNetworkInterface);
            return -6;
        }
        if (NULL == (pExternalNetworkInterface = ACMNetProxy::PCapInterface::getPCapInterface (pszExternalInterfaceName))) {
            checkAndLogMsg ("main", Logger::L_SevereError,
                            "could not open device <%s>\n", pExternalNetworkInterface);
            return -6;
        }

        // Retrieve MAC address
        const uint8 *pszInternalMACAddr = NULL, *pszExternalMACAddr = NULL;
        if (NULL == (pszInternalMACAddr = pInternalNetworkInterface->getMACAddr())) {
            checkAndLogMsg ("main", Logger::L_SevereError,
                            "could not obtain MAC address for device <%s>\n", pszInternalInterfaceName);
            return -7;
        }
        if (NULL == (pszExternalMACAddr = pExternalNetworkInterface->getMACAddr())) {
            checkAndLogMsg ("main", Logger::L_SevereError,
                            "could not obtain MAC address for device <%s>\n", pszExternalInterfaceName);
            return -8;
        }
        ACMNetProxy::buildEthernetMACAddressFromString (ACMNetProxy::NetProxyApplicationParameters::NETPROXY_INTERNAL_INTERFACE_MAC_ADDR, pszInternalMACAddr);
        ACMNetProxy::buildEthernetMACAddressFromString (ACMNetProxy::NetProxyApplicationParameters::NETPROXY_EXTERNAL_INTERFACE_MAC_ADDR, pszExternalMACAddr);

        // Retrieve IPv4 address
        if ((ACMNetProxy::NetProxyApplicationParameters::NETPROXY_IP_ADDR == 0) && (configuredIPv4Addr.getIPAddress() == 0)) {
            // Try and retrieve interface IP from the device itself
            ACMNetProxy::NetProxyApplicationParameters::NETPROXY_IP_ADDR = pExternalNetworkInterface->getIPv4Addr() ?
                                                                           pExternalNetworkInterface->getIPv4Addr()->ui32Addr : 0;
            if (ACMNetProxy::NetProxyApplicationParameters::NETPROXY_IP_ADDR == 0) {
                checkAndLogMsg ("main", Logger::L_SevereError,
                                "could not determine IP address of the external interface\n");
                return -9;
            }
            else {
                checkAndLogMsg ("main", Logger::L_Info,
                                "retrieved IP address %s for network interface <%s>\n",
                                InetAddr(ACMNetProxy::NetProxyApplicationParameters::NETPROXY_IP_ADDR).getIPAsString(),
                                pszExternalInterfaceName);
            }
        }
        else if (ACMNetProxy::NetProxyApplicationParameters::NETPROXY_IP_ADDR == 0) {
            ACMNetProxy::NetProxyApplicationParameters::NETPROXY_IP_ADDR = configuredIPv4Addr.getIPAddress();
            checkAndLogMsg ("main", Logger::L_Info,
                            "set IP address %s for network interface <%s>\n",
                            InetAddr(ACMNetProxy::NetProxyApplicationParameters::NETPROXY_IP_ADDR).getIPAsString(),
                            pszExternalInterfaceName);
        }

        // Retrieve IPv4 Netmask
        if ((ACMNetProxy::NetProxyApplicationParameters::NETPROXY_NETWORK_NETMASK == 0) && (configuredNetmask.getIPAddress() == 0)) {
            // Try and retrieve netmask from the device itself
            ACMNetProxy::NetProxyApplicationParameters::NETPROXY_NETWORK_NETMASK = pExternalNetworkInterface->getNetmask() ?
                                                                                   pExternalNetworkInterface->getNetmask()->ui32Addr : 0;
            if (ACMNetProxy::NetProxyApplicationParameters::NETPROXY_NETWORK_NETMASK == 0) {
                checkAndLogMsg ("main", Logger::L_SevereError,
                                "could not determine Netmask of the external interface\n");
                return -10;
            }
            else {
                checkAndLogMsg ("main", Logger::L_Info,
                                "retrieved netmask %s for network interface <%s>\n",
                                InetAddr(ACMNetProxy::NetProxyApplicationParameters::NETPROXY_NETWORK_NETMASK).getIPAsString(),
                                pszExternalInterfaceName);
            }
        }
        else if (ACMNetProxy::NetProxyApplicationParameters::NETPROXY_NETWORK_NETMASK == 0) {
            ACMNetProxy::NetProxyApplicationParameters::NETPROXY_NETWORK_NETMASK = configuredNetmask.getIPAddress();
            checkAndLogMsg ("main", Logger::L_Info,
                            "set netmask %s for network interface <%s>\n",
                            InetAddr(ACMNetProxy::NetProxyApplicationParameters::NETPROXY_NETWORK_NETMASK).getIPAsString(),
                            pszExternalInterfaceName);
        }
        // Retrieve IPv4 address of the Default Gateway
        if ((ACMNetProxy::NetProxyApplicationParameters::NETWORK_GATEWAY_NODE_IP_ADDR == 0) && (configuredGateway.getIPAddress() == 0)) {
            // Try and retrieve Default Gateway from the device itself
            ACMNetProxy::NetProxyApplicationParameters::NETWORK_GATEWAY_NODE_IP_ADDR = pExternalNetworkInterface->getDefaultGateway() ?
                                                                                       pExternalNetworkInterface->getDefaultGateway()->ui32Addr : 0;
            if (ACMNetProxy::NetProxyApplicationParameters::NETWORK_GATEWAY_NODE_IP_ADDR == 0) {
                checkAndLogMsg ("main", Logger::L_SevereError,
                                "could not determine Default Gateway of the external interface\n");
                return -11;
            }
            else {
                checkAndLogMsg ("main", Logger::L_Info,
                                "retrieved IP address %s as Default Gateway for the network interface <%s>\n",
                                InetAddr(ACMNetProxy::NetProxyApplicationParameters::NETWORK_GATEWAY_NODE_IP_ADDR).getIPAsString(),
                                pszExternalInterfaceName);
            }
        }
        else if (ACMNetProxy::NetProxyApplicationParameters::NETWORK_GATEWAY_NODE_IP_ADDR == 0) {
            ACMNetProxy::NetProxyApplicationParameters::NETWORK_GATEWAY_NODE_IP_ADDR = configuredNetmask.getIPAddress();
            checkAndLogMsg ("main", Logger::L_Info,
                            "set gateway IP address %s for network interface <%s>\n",
                            InetAddr(ACMNetProxy::NetProxyApplicationParameters::NETPROXY_NETWORK_NETMASK).getIPAsString(),
                            pszExternalInterfaceName);
        }
    }
    else {
        // Running in host mode: use TAP interface
        pInternalNetworkInterface = ACMNetProxy::TapInterface::getTAPInterface();
        // Retrieve IPv4 address
        if ((ACMNetProxy::NetProxyApplicationParameters::NETPROXY_IP_ADDR == 0U) && (configuredIPv4Addr.getIPAddress() == 0U)) {
            ACMNetProxy::NetProxyApplicationParameters::NETPROXY_IP_ADDR = pInternalNetworkInterface->getIPv4Addr() ?
                                                                           pInternalNetworkInterface->getIPv4Addr()->ui32Addr : 0;
            if (ACMNetProxy::NetProxyApplicationParameters::NETPROXY_IP_ADDR == 0) {
                checkAndLogMsg ("main", Logger::L_SevereError,
                                "could not determine IP address of TUN/TAP interface and "
                                "no IP address was specified in the config file\n");
                return -12;
            }
            else {
                checkAndLogMsg ("main", Logger::L_Info,
                                "retrieved IP address %s for the TUN/TAP interface\n",
                                InetAddr(ACMNetProxy::NetProxyApplicationParameters::NETPROXY_IP_ADDR).getIPAsString());
            }
        }
        else if (pInternalNetworkInterface->getIPv4Addr() && (configuredIPv4Addr.getIPAddress() != 0U) &&
                 (pInternalNetworkInterface->getIPv4Addr()->ui32Addr != configuredIPv4Addr.getIPAddress())) {
            ACMNetProxy::NetProxyApplicationParameters::NETPROXY_IP_ADDR = pInternalNetworkInterface->getIPv4Addr()->ui32Addr;
            checkAndLogMsg ("main", Logger::L_Warning,
                            "configured IP address <%s> does not match the TAP interface address <%s>; "
                            "the address retrieved directly from the virtual interface will be used\n",
                            configuredIPv4Addr.getIPAsString(),
                            InetAddr(pInternalNetworkInterface->getIPv4Addr()->ui32Addr).getIPAsString());
        }

        // Retrieve MTU
        if ((ACMNetProxy::NetProxyApplicationParameters::TAP_INTERFACE_MTU == 0U) && (ui16ConfiguredMTU == 0U)) {
            ACMNetProxy::NetProxyApplicationParameters::TAP_INTERFACE_MTU = pInternalNetworkInterface->getMTUSize();
            if (ACMNetProxy::NetProxyApplicationParameters::TAP_INTERFACE_MTU == 0) {
                checkAndLogMsg ("main", Logger::L_SevereError,
                                "could not determine the MTU of the TUN/TAP interface and "
                                "no MTU size was specified in the config file\n");
                return -13;
            }
            else {
                checkAndLogMsg ("main", Logger::L_Info,
                                "retrieved MTU size of %hu bytes for the TUN/TAP interface\n",
                                ACMNetProxy::NetProxyApplicationParameters::TAP_INTERFACE_MTU);
            }
        }
        else if (pInternalNetworkInterface->getMTUSize() && ui16ConfiguredMTU &&
                 (pInternalNetworkInterface->getMTUSize() != ui16ConfiguredMTU)) {
            ACMNetProxy::NetProxyApplicationParameters::TAP_INTERFACE_MTU = pInternalNetworkInterface->getMTUSize();
            checkAndLogMsg ("main", Logger::L_Warning,
                            "configured MTU size (%hu bytes) does not match the value retrieved from the "
                            "TUN/TAP interface (%hu bytes); the latter value will be used\n",
                            ui16ConfiguredMTU, pInternalNetworkInterface->getMTUSize());
        }
    }
    
    // Check if the NPUID was set and, if not, set it to the 32-bits value of the IP address of the (external) network interface
    if (ACMNetProxy::NetProxyApplicationParameters::NETPROXY_UNIQUE_ID == 0) {
        ACMNetProxy::NetProxyApplicationParameters::NETPROXY_UNIQUE_ID = ACMNetProxy::NetProxyApplicationParameters::GATEWAY_MODE ?
                                                                         ACMNetProxy::NetProxyApplicationParameters::NETPROXY_IP_ADDR : 0;
        if (ACMNetProxy::NetProxyApplicationParameters::NETPROXY_UNIQUE_ID == 0) {
            // Try and retrieve local host IP address
            const char *pszExternalInterfaceName = pCfgManager->getValue ("ExternalInterfaceName");
            if (pszExternalInterfaceName == NULL) {
                checkAndLogMsg ("main", Logger::L_SevereError,
                                "external interface not specified in the config file, but it is necessary to configure "
                                "the UniqueID of the local instance of NetProxy if not explicitly configured\n");
                return -14;
            }
            if (NULL == (pExternalNetworkInterface = ACMNetProxy::PCapInterface::getPCapInterface (pszExternalInterfaceName))) {
                checkAndLogMsg ("main", Logger::L_SevereError,
                                "could not open device <%s>, necessary to configure the UniqueID of the local instance of NetProxy\n",
                                pExternalNetworkInterface);
                return -15;
            }
            ACMNetProxy::NetProxyApplicationParameters::NETPROXY_UNIQUE_ID = pExternalNetworkInterface->getIPv4Addr() ?
                                                                             pExternalNetworkInterface->getIPv4Addr()->ui32Addr : 0;
            if (ACMNetProxy::NetProxyApplicationParameters::NETPROXY_UNIQUE_ID == 0) {
                checkAndLogMsg ("main", Logger::L_SevereError,
                                "could not retrieve IP address from device <%s>, necessary to configure the UniqueID "
                                "of the local instance of NetProxy\n", pExternalNetworkInterface);
                return -16;
            }
            else {
                delete pExternalNetworkInterface;
                pExternalNetworkInterface = NULL;
            }
        }
    }

    ACMNetProxy::PacketRouter *pr = ACMNetProxy::PacketRouter::getPacketRouter();
    if (0 != (rc = pr->init (pInternalNetworkInterface, pExternalNetworkInterface))) {
        checkAndLogMsg ("main", Logger::L_SevereError,
                        "init() on PacketRouter failed with rc = %d\n", rc);
        return -14;
    }

    signal (SIGINT, ACMNetProxy::terminateExecution);
    signal (SIGTERM, ACMNetProxy::terminateExecution);
    #if defined (WIN32)
        signal (SIGBREAK, ACMNetProxy::terminateExecution);      // WIN32 OS sends a SIGBREAK whenever an user closes a console application clicking on the X button
    #endif

    if (0 != (rc = pr->startThreads())) {
        checkAndLogMsg ("main", Logger::L_SevereError,
                        "startThreads() on PacketRouter failed with rc = %d\n", rc);
        return -15;
    }

    // Send ARP request for the MAC address of the gateway
    if (ACMNetProxy::NetProxyApplicationParameters::GATEWAY_MODE &&
        (0 != (rc = ACMNetProxy::PacketRouter::sendARPRequestForGatewayMACAddress()))) {
        checkAndLogMsg ("main", Logger::L_SevereError,
                        "sendARPRequestForGatewayMACAddress() on PacketRouter failed with rc = %d\n", rc);
        return -16;
    }

    //#if defined (WIN32)
    if (0 != pr->joinThreads()) {
        checkAndLogMsg ("main", Logger::L_SevereError,
                        "joinThreads() on PacketRouter failed with rc = %d\n", rc);
        return -17;
    }
    else {
        checkAndLogMsg ("main", Logger::L_Info,
                        "Execution terminated successfully! Exiting program...\n");
        sleepForMilliseconds (1000);
    }

    return 0;
}