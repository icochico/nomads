/*
 * GUIMonitor.java
 * 
 * This file is part of the IHMC Mockets Library/Component
 * Copyright (c) 2002-2014 IHMC.
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
 * @author ebenvegnu
 */

package us.ihmc.mockets.monitor;

import us.ihmc.mockets.monitor.MocketStatus.MocketStatisticsInfo;

import java.util.concurrent.TimeUnit;

public class GUIMonitor extends javax.swing.JFrame implements MocketStatusListener
{
    /**
     * Creates new form GUIMonitor
     */
    public GUIMonitor()
    {
        _stream  = new long[MAX_NUM_STEAMS];
        _numStreams = 0;
        _mostRecUpdate = new MocketStatus.Update[MAX_NUM_STEAMS];
        for (int i=0; i<MAX_NUM_STEAMS; i++) {
            _mostRecUpdate[i] = new MocketStatus.Update();
        }
        initComponents();
        clearLabels();
        try {
            Monitor m = new Monitor();
            m.setListener (this);
            m.start();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jfPID = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jfIdentifier = new javax.swing.JLabel();
        jfLocalPort = new javax.swing.JLabel();
        jfRemoteAddress = new javax.swing.JLabel();
        jfRemotePort = new javax.swing.JLabel();
        jPanel2 = new javax.swing.JPanel();
        jLabel7 = new javax.swing.JLabel();
        jfLastContact = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();
        jfRTT = new javax.swing.JLabel();
        jLabel11 = new javax.swing.JLabel();
        jLabel12 = new javax.swing.JLabel();
        jfSentBytes = new javax.swing.JLabel();
        jLabel14 = new javax.swing.JLabel();
        jfSentPackets = new javax.swing.JLabel();
        jLabel16 = new javax.swing.JLabel();
        jfRetr = new javax.swing.JLabel();
        jLabel18 = new javax.swing.JLabel();
        jLabel19 = new javax.swing.JLabel();
        jfRecBytes = new javax.swing.JLabel();
        jLabel21 = new javax.swing.JLabel();
        jfRecPackets = new javax.swing.JLabel();
        jLabel23 = new javax.swing.JLabel();
        jLabel24 = new javax.swing.JLabel();
        jfDiscDup = new javax.swing.JLabel();
        jLabel26 = new javax.swing.JLabel();
        jfDiscNoRoom = new javax.swing.JLabel();
        jLabel28 = new javax.swing.JLabel();
        jfDiscReassSkipped = new javax.swing.JLabel();
        jLabel35 = new javax.swing.JLabel();
        jLabel36 = new javax.swing.JLabel();
        jfPPQDataSize = new javax.swing.JLabel();
        jLabel38 = new javax.swing.JLabel();
        jfPPQSize = new javax.swing.JLabel();
        jLabel40 = new javax.swing.JLabel();
        jLabel41 = new javax.swing.JLabel();
        jfRelSeqDataSize = new javax.swing.JLabel();
        jLabel43 = new javax.swing.JLabel();
        jfRelSeqSize = new javax.swing.JLabel();
        jLabel45 = new javax.swing.JLabel();
        jLabel46 = new javax.swing.JLabel();
        jfRelUnseqDataSize = new javax.swing.JLabel();
        jLabel48 = new javax.swing.JLabel();
        jfRelUnseqSize = new javax.swing.JLabel();
        jcbStream = new javax.swing.JComboBox();
        jLabel6 = new javax.swing.JLabel();
        jfNewSelection = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jPanel1.setBorder(javax.swing.BorderFactory.createTitledBorder("Endpoint Info"));

        jLabel1.setText("PID");

        jfPID.setText("jLabel2");

        jLabel2.setText("Identifier");

        jLabel3.setText("Local Port");

        jLabel4.setText("Remote Address");

        jLabel5.setText("Remote Port");

        jfIdentifier.setText("jLabel6");

        jfLocalPort.setText("jLabel6");

        jfRemoteAddress.setText("jLabel6");

        jfRemotePort.setText("jLabel6");

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel1)
                    .addComponent(jLabel2)
                    .addComponent(jLabel3)
                    .addComponent(jLabel4)
                    .addComponent(jLabel5))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jfPID, javax.swing.GroupLayout.DEFAULT_SIZE, 125, Short.MAX_VALUE)
                    .addComponent(jfIdentifier, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jfLocalPort, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jfRemoteAddress, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jfRemotePort, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(jfPID))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(jfIdentifier))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(jfLocalPort))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(jfRemoteAddress))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5)
                    .addComponent(jfRemotePort))
                .addGap(0, 12, Short.MAX_VALUE))
        );

        jPanel2.setBorder(javax.swing.BorderFactory.createTitledBorder("Statistics"));

        jLabel7.setText("Last contact time");

        jfLastContact.setText("jLabel8");

        jLabel9.setText("Estimated RTT");

        jfRTT.setText("jLabel10");

        jLabel11.setText("Sent:");

        jLabel12.setText("bytes");

        jfSentBytes.setText("jLabel13");

        jLabel14.setText("packets");

        jfSentPackets.setText("jLabel15");

        jLabel16.setText("(retransmits");

        jfRetr.setText("jLabel17");

        jLabel18.setText("Received:");

        jLabel19.setText("bytes");

        jfRecBytes.setText("jLabel20");

        jLabel21.setText("packets");

        jfRecPackets.setText("jLabel22");

        jLabel23.setText("Discarded:");

        jLabel24.setText("duplicated");

        jfDiscDup.setText("jLabel25");

        jLabel26.setText("no room");

        jfDiscNoRoom.setText("jLabel27");

        jLabel28.setText("reassemply skipped");

        jfDiscReassSkipped.setText("jLabel29");

        jLabel35.setText("Pending packet queue:");

        jLabel36.setText("data size");

        jfPPQDataSize.setText("jLabel37");

        jLabel38.setText("queue size");

        jfPPQSize.setText("jLabel39");

        jLabel40.setText("Unacknowledged Reliable Sequenced queue:");

        jLabel41.setText("data size");

        jfRelSeqDataSize.setText("jLabel42");

        jLabel43.setText("queue size");

        jfRelSeqSize.setText("jLabel44");

        jLabel45.setText("Unacknowledged Reliable Unsequenced queue:");

        jLabel46.setText("data size");

        jfRelUnseqDataSize.setText("jLabel47");

        jLabel48.setText("queue size");

        jfRelUnseqSize.setText("jLabel49");

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGap(46, 46, 46)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addComponent(jLabel26)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jfDiscNoRoom))
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addComponent(jLabel24)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jfDiscDup))
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addComponent(jLabel28)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jfDiscReassSkipped)))
                .addGap(0, 0, Short.MAX_VALUE))
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addComponent(jLabel7)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jfLastContact))
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addComponent(jLabel9)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jfRTT))
                            .addComponent(jLabel11)
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addGap(36, 36, 36)
                                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(jPanel2Layout.createSequentialGroup()
                                        .addComponent(jLabel14)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(jfSentPackets))
                                    .addGroup(jPanel2Layout.createSequentialGroup()
                                        .addComponent(jLabel12)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(jfSentBytes))
                                    .addGroup(jPanel2Layout.createSequentialGroup()
                                        .addComponent(jLabel16)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(jfRetr))))
                            .addComponent(jLabel18)))
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addGap(43, 43, 43)
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addComponent(jLabel21)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jfRecPackets))
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addComponent(jLabel19)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jfRecBytes))))
                    .addComponent(jLabel23)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addGap(40, 40, 40)
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addComponent(jLabel38)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jfPPQSize))
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addComponent(jLabel36)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jfPPQDataSize))))
                    .addComponent(jLabel35)
                    .addComponent(jLabel40)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addGap(43, 43, 43)
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addComponent(jLabel43)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jfRelSeqSize))
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addComponent(jLabel41)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jfRelSeqDataSize))))
                    .addComponent(jLabel45)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addGap(47, 47, 47)
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addComponent(jLabel48)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jfRelUnseqSize))
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addComponent(jLabel46)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jfRelUnseqDataSize)))))
                .addContainerGap())
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel7)
                    .addComponent(jfLastContact))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel9)
                    .addComponent(jfRTT))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel11)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel12)
                    .addComponent(jfSentBytes))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel14)
                    .addComponent(jfSentPackets))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel16)
                    .addComponent(jfRetr))
                .addGap(18, 18, 18)
                .addComponent(jLabel18)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel19)
                    .addComponent(jfRecBytes))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel21)
                    .addComponent(jfRecPackets))
                .addGap(18, 18, 18)
                .addComponent(jLabel23)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel24)
                    .addComponent(jfDiscDup))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel26)
                    .addComponent(jfDiscNoRoom))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel28)
                    .addComponent(jfDiscReassSkipped))
                .addGap(18, 18, 18)
                .addComponent(jLabel35)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel36)
                    .addComponent(jfPPQDataSize))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel38)
                    .addComponent(jfPPQSize))
                .addGap(18, 18, 18)
                .addComponent(jLabel40)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel41)
                    .addComponent(jfRelSeqDataSize))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel43)
                    .addComponent(jfRelSeqSize))
                .addGap(18, 18, 18)
                .addComponent(jLabel45)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel46)
                    .addComponent(jfRelUnseqDataSize))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel48)
                    .addComponent(jfRelUnseqSize))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jcbStream.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jcbStreamActionPerformed(evt);
            }
        });

        jLabel6.setText("Select stream");

        jfNewSelection.setText("jLabel50");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel6)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jcbStream, javax.swing.GroupLayout.PREFERRED_SIZE, 106, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jfNewSelection))
                            .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(0, 89, Short.MAX_VALUE)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(17, 17, 17)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jcbStream, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel6)
                    .addComponent(jfNewSelection))
                .addGap(18, 18, 18)
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void clearLabels()
    {
        jfNewSelection.setText("");
        jfPID.setText("");
        jfIdentifier.setText("");
        jfLocalPort.setText("");
        jfRemoteAddress.setText("");
        jfRemotePort.setText("");
        jfLastContact.setText("");
        jfRTT.setText("");
        jfSentBytes.setText("");
        jfSentPackets.setText("");
        jfRetr.setText("");
        jfRecBytes.setText("");
        jfRecPackets.setText("");
        jfDiscDup.setText("");
        jfDiscNoRoom.setText("");
        jfDiscReassSkipped.setText("");
        jfPPQDataSize.setText("");
        jfPPQSize.setText("");
        jfRelSeqDataSize.setText("");
        jfRelSeqSize.setText("");
        jfRelUnseqDataSize.setText("");
        jfRelUnseqSize.setText("");
        
    }
    
    private void jcbStreamActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jcbStreamActionPerformed
        _selectedStream = ((Long) jcbStream.getSelectedItem()).longValue();
        // Visualize the most recent update until a new one becomes available
        int streamIndex = -1;
        for (int i=0; i<_numStreams; i++) {
            if (_stream[i] == _selectedStream) {
                streamIndex = i;
                break;
            }
        }
        if (streamIndex != -1) {
            jfNewSelection.setText ("Waiting for next update...");
            // Show the most recent update for the selected stream until a new one is received
            jfPID.setText (Long.toString (_mostRecUpdate[streamIndex].epi.PID));
            jfIdentifier.setText (_mostRecUpdate[streamIndex].epi.identifier);
            jfLocalPort.setText (Long.toString (_mostRecUpdate[streamIndex].epi.localPort));
            jfRemoteAddress.setText (_mostRecUpdate[streamIndex].epi.remoteAddress.toString().replace ('/', '\0'));
            jfRemotePort.setText (Long.toString (_mostRecUpdate[streamIndex].epi.remotePort));
            Long totalLastContactTime = System.currentTimeMillis() - _mostRecUpdate[streamIndex].msi.lastContactTime;
            Long timeSeconds = TimeUnit.MILLISECONDS.toSeconds (totalLastContactTime); //Calculate time in seconds
            jfLastContact.setText (Long.toString (timeSeconds));
            jfSentBytes.setText (Long.toString (_mostRecUpdate[streamIndex].msi.sentBytes));
            jfSentPackets.setText (Long.toString (_mostRecUpdate[streamIndex].msi.sentPackets));
            jfRetr.setText (Long.toString (_mostRecUpdate[streamIndex].msi.retransmits)+")");
            jfRecBytes.setText (Long.toString (_mostRecUpdate[streamIndex].msi.receivedBytes));
            jfRecPackets.setText (Long.toString (_mostRecUpdate[streamIndex].msi.receivedPackets));
            jfDiscDup.setText (Long.toString (_mostRecUpdate[streamIndex].msi.duplicatedDiscardedPackets));
            jfDiscNoRoom.setText (Long.toString (_mostRecUpdate[streamIndex].msi.noRoomDiscardedPackets));
            jfDiscReassSkipped.setText (Long.toString (_mostRecUpdate[streamIndex].msi.reassemblySkippedDiscardedPackets));
            jfRTT.setText (Float.toString (_mostRecUpdate[streamIndex].msi.estimatedRTT));
            jfPPQDataSize.setText (Long.toString (_mostRecUpdate[streamIndex].msi.pendingDataSize));
            jfPPQSize.setText (Long.toString (_mostRecUpdate[streamIndex].msi.pendingPacketQueueSize));
            jfRelSeqDataSize.setText (Long.toString (_mostRecUpdate[streamIndex].msi.reliableSequencedDataSize));
            jfRelSeqSize.setText (Long.toString (_mostRecUpdate[streamIndex].msi.reliableSequencedPacketQueueSize));
            jfRelUnseqDataSize.setText (Long.toString (_mostRecUpdate[streamIndex].msi.reliableUnsequencedDataSize));
            jfRelUnseqSize.setText (Long.toString (_mostRecUpdate[streamIndex].msi.reliableUnsequencedPacketQueueSize));
        }
        else {
            // Clear visualized data
            clearLabels();
            jfNewSelection.setText ("Waiting for next update...");
        }
    }//GEN-LAST:event_jcbStreamActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /*
         * Set the Nimbus look and feel
         */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /*
         * If Nimbus (introduced in Java SE 6) is not available, stay with the
         * default look and feel. For details see
         * http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(GUIMonitor.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(GUIMonitor.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(GUIMonitor.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(GUIMonitor.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /*
         * Create and display the form
         */
        java.awt.EventQueue.invokeLater(new Runnable() {

            public void run() {
                new GUIMonitor().setVisible(true);
            }
        });
    }
    
    public void statusUpdateArrived (MocketStatus.EndPointsInfo epi, byte msgType)
    {
        System.out.println ("\nStatus Update <" + MocketStatus.MocketStatusNoticeType.values()[msgType] + "> received from " + epi.PID + " " + epi.identifier);
    }

    public void statisticsInfoUpdateArrived (MocketStatus.EndPointsInfo epi, MocketStatisticsInfo msi)
    {
        // Check if this is a new stream and in that case update the combo box
        boolean newStream = true;
        for (int i=0; i<_numStreams; i++) {
            //System.out.println ("Comparing "+_stream[i]+" and "+epi.PID);
            if (_stream[i] == epi.PID) {
                // Save most recent update for this stream
                _mostRecUpdate[i].msi = msi;
                newStream = false;
                break;
            }
        }
        if (newStream) {
            // Save the new stream
            try {
                _stream[_numStreams] = epi.PID;
                // Save most recent update for this stream
                _mostRecUpdate[_numStreams].epi = epi;
                _mostRecUpdate[_numStreams].msi = msi;
                _numStreams++;
            }
            catch (IndexOutOfBoundsException ex) {
                System.out.println ("Error: too many streams "+ex);
                System.exit (-1);
            }
            // Update the combo box
            jcbStream.addItem (new Long (epi.PID));
        }
        
        // Update stats if this update matches the selected stream in the combo box
        // If there is a single item in the combo box it will be automatically selected
        if (_selectedStream == epi.PID) {
            jfNewSelection.setText ("");
            jfPID.setText (Long.toString (epi.PID));
            jfIdentifier.setText (epi.identifier);
            jfLocalPort.setText (Long.toString (epi.localPort));
            jfRemoteAddress.setText (epi.remoteAddress.toString().replace ('/', '\0'));
            jfRemotePort.setText (Long.toString (epi.remotePort));
            
            jfLastContact.setText (Long.toString (msi.lastContactTime));
            jfSentBytes.setText (Long.toString (msi.sentBytes));
            jfSentPackets.setText (Long.toString (msi.sentPackets));
            jfRetr.setText (Long.toString (msi.retransmits)+")");
            jfRecBytes.setText (Long.toString (msi.receivedBytes));
            jfRecPackets.setText (Long.toString (msi.receivedPackets));
            jfDiscDup.setText (Long.toString (msi.duplicatedDiscardedPackets));
            jfDiscNoRoom.setText (Long.toString (msi.noRoomDiscardedPackets));
            jfDiscReassSkipped.setText (Long.toString (msi.reassemblySkippedDiscardedPackets));
            jfRTT.setText (Float.toString (msi.estimatedRTT));
            jfPPQDataSize.setText (Long.toString (msi.pendingDataSize));
            jfPPQSize.setText (Long.toString (msi.pendingPacketQueueSize));
            jfRelSeqDataSize.setText (Long.toString (msi.reliableSequencedDataSize));
            jfRelSeqSize.setText (Long.toString (msi.reliableSequencedPacketQueueSize));
            jfRelUnseqDataSize.setText (Long.toString (msi.reliableUnsequencedDataSize));
            jfRelUnseqSize.setText (Long.toString (msi.reliableUnsequencedPacketQueueSize));
        }
    }
    
    public void statisticsInfoUpdateArrived (MocketStatus.EndPointsInfo epi, MocketStatus.MessageStatisticsInfo messSi)
    {
        
    }
    
    private long _stream[];
    private int _numStreams;
    private MocketStatus.Update _mostRecUpdate[];
    private long _selectedStream;
    private static int MAX_NUM_STEAMS = 15;
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel14;
    private javax.swing.JLabel jLabel16;
    private javax.swing.JLabel jLabel18;
    private javax.swing.JLabel jLabel19;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel21;
    private javax.swing.JLabel jLabel23;
    private javax.swing.JLabel jLabel24;
    private javax.swing.JLabel jLabel26;
    private javax.swing.JLabel jLabel28;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel35;
    private javax.swing.JLabel jLabel36;
    private javax.swing.JLabel jLabel38;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel40;
    private javax.swing.JLabel jLabel41;
    private javax.swing.JLabel jLabel43;
    private javax.swing.JLabel jLabel45;
    private javax.swing.JLabel jLabel46;
    private javax.swing.JLabel jLabel48;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JComboBox jcbStream;
    private javax.swing.JLabel jfDiscDup;
    private javax.swing.JLabel jfDiscNoRoom;
    private javax.swing.JLabel jfDiscReassSkipped;
    private javax.swing.JLabel jfIdentifier;
    private javax.swing.JLabel jfLastContact;
    private javax.swing.JLabel jfLocalPort;
    private javax.swing.JLabel jfNewSelection;
    private javax.swing.JLabel jfPID;
    private javax.swing.JLabel jfPPQDataSize;
    private javax.swing.JLabel jfPPQSize;
    private javax.swing.JLabel jfRTT;
    private javax.swing.JLabel jfRecBytes;
    private javax.swing.JLabel jfRecPackets;
    private javax.swing.JLabel jfRelSeqDataSize;
    private javax.swing.JLabel jfRelSeqSize;
    private javax.swing.JLabel jfRelUnseqDataSize;
    private javax.swing.JLabel jfRelUnseqSize;
    private javax.swing.JLabel jfRemoteAddress;
    private javax.swing.JLabel jfRemotePort;
    private javax.swing.JLabel jfRetr;
    private javax.swing.JLabel jfSentBytes;
    private javax.swing.JLabel jfSentPackets;
    // End of variables declaration//GEN-END:variables
}
