/*
 * ActiveConnection.cpp
 *
 * This file is part of the IHMC NetProxy Library/Component
 * Copyright (c) 2010-2016 IHMC.
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
 */

#include "ActiveConnection.h"
#include "Connection.h"
#include "UDPConnector.h"


using namespace NOMADSUtil;

namespace ACMNetProxy
{
    Connection * const ActiveConnection::getActiveConnection (ConnectorType connectorType) const
    {
        switch (connectorType) {
        case CT_MOCKETS:
            return _pMocketsConnection;
        case CT_SOCKET:
            return _pSocketConnection;
        case CT_CSR:
            return _pCSRConnection;
        default:
            break;
        }

        return NULL;
    }

    const InetAddr * const ActiveConnection::getActiveConnectionAddr (ConnectorType connectorType) const
    {
        switch (connectorType) {
        case CT_MOCKETS:
            return _pMocketsConnection ? _pMocketsConnection->getRemoteProxyInetAddr() : NULL;
        case CT_SOCKET:
            return _pSocketConnection ? _pSocketConnection->getRemoteProxyInetAddr() : NULL;
        case CT_CSR:
            return _pCSRConnection ? _pCSRConnection->getRemoteProxyInetAddr() : NULL;
        default:
            break;
        }

        return NULL;
    }

    Connection * const ActiveConnection::setNewActiveConnection (Connection * const pActiveConnection)
    {
        if (!pActiveConnection) {
            return NULL;
        }

        Connection * const pOldConnection = getActiveConnection (pActiveConnection->getConnectorType());
        if (pOldConnection == pActiveConnection) {
            return NULL;
        }

        switch (pActiveConnection->getConnectorType()) {
        case CT_MOCKETS:
            _pMocketsConnection = pActiveConnection;
            break;
        case CT_SOCKET:
            _pSocketConnection = pActiveConnection;
            break;
        case CT_CSR:
            _pCSRConnection = pActiveConnection;
            break;
        case CT_UDP:
        case CT_UNDEF:
            return NULL;
        }

        return pOldConnection;
    }

    Connection * const ActiveConnection::removeActiveConnection (const Connection * const pActiveConnection)
    {
        if (!pActiveConnection || (pActiveConnection->getConnectorType() == CT_UNDEF) ||
            (pActiveConnection->getConnectorType() == CT_UDP)) {
            return NULL;
        }

        if (getActiveConnection (pActiveConnection->getConnectorType()) == pActiveConnection) {
            return removeActiveConnectionByType (pActiveConnection->getConnectorType());
        }

        return NULL;
    }

    // This method is private and should only be invoked with a MOCKETS, SOCKET, or CSR connectorType
    Connection * const ActiveConnection::removeActiveConnectionByType (ConnectorType connectorType)
    {
        Connection * const pOldConnection = getActiveConnection (connectorType);
        switch (connectorType) {
        case CT_MOCKETS:
            _pMocketsConnection = NULL;
            break;
        case CT_SOCKET:
            _pSocketConnection = NULL;
            break;
        case CT_CSR:
            _pCSRConnection = NULL;
            break;
        default:
            return NULL;
        }

        return pOldConnection;
    }
}
