/////////////////////////////////////////////////////////////
// Created by: Synopsys DC Expert(TM) in wire load mode
// Version   : O-2018.06-SP4
// Date      : Sat Nov 21 12:25:48 2020
/////////////////////////////////////////////////////////////


module s298 ( GND, VDD, CK, G0, G1, G117, G118, G132, G133, G2, G66, G67 );
  input GND, VDD, CK, G0, G1, G2;
  output G117, G118, G132, G133, G66, G67;
  wire   G29, G30, G34, G39, G44, G56, G86, G92, G98, G102, G107, G113, G119,
         G125, n1, n2, n3, n4, n6, n7, n8, n9, n10, n11, n12, n13, n16, n17,
         n18, n19, n20, n21, n22, n23, n24, n25, n26, n27, n28, n29, n30, n31,
         n32, n33, n34, n35, n36, n37, n38, n39, n40, n41, n42, n43, n44, n45,
         n46, n47, n48, n49, n50, n51, n52, n53, n54, n55, n56, n57, n58, n59,
         n60, n61, n62, n63, n64, n65, n66, n67, n68, n69, n70, n71, n72, n73,
         n76, n77, n78, n79, n80, n81, n82, n83, n84;

  DFF_X1 DFF_5 ( .D(G56), .CK(CK), .Q(n84), .QN(n72) );
  DFF_X1 DFF_6 ( .D(G86), .CK(CK), .Q(G66) );
  DFF_X1 DFF_7 ( .D(G92), .CK(CK), .Q(G67), .QN(n73) );
  DFF_X1 DFF_8 ( .D(G98), .CK(CK), .Q(G117) );
  DFF_X1 DFF_9 ( .D(G102), .CK(CK), .Q(G118), .QN(n78) );
  DFF_X1 DFF_10 ( .D(G107), .CK(CK), .Q(G132) );
  DFF_X1 DFF_11 ( .D(G113), .CK(CK), .Q(G133) );
  DFF_X1 DFF_0 ( .D(G29), .CK(CK), .Q(n3), .QN(n83) );
  DFF_X1 DFF_12 ( .D(G119), .CK(CK), .Q(n16), .QN(n77) );
  DFF_X1 DFF_13 ( .D(G125), .CK(CK), .Q(n17), .QN(n76) );
  DFF_X1 DFF_1 ( .D(G30), .CK(CK), .Q(n7), .QN(n81) );
  DFF_X1 DFF_2 ( .D(G34), .CK(CK), .Q(n10), .QN(n80) );
  DFF_X1 DFF_3 ( .D(G39), .CK(CK), .Q(n11), .QN(n82) );
  DFF_X1 DFF_4 ( .D(G44), .CK(CK), .Q(n13), .QN(n79) );
  OR2_X1 U86 ( .A1(n84), .A2(n33), .ZN(n69) );
  INV_X1 U87 ( .A(n46), .ZN(n6) );
  INV_X1 U88 ( .A(n44), .ZN(n2) );
  INV_X1 U89 ( .A(n29), .ZN(n9) );
  NOR2_X1 U90 ( .A1(n11), .A2(n10), .ZN(n29) );
  NOR2_X1 U91 ( .A1(n7), .A2(n10), .ZN(n46) );
  INV_X1 U92 ( .A(n22), .ZN(n4) );
  INV_X1 U93 ( .A(n71), .ZN(n12) );
  NAND2_X1 U94 ( .A1(n47), .A2(n10), .ZN(n44) );
  INV_X1 U95 ( .A(n41), .ZN(n1) );
  INV_X1 U96 ( .A(n28), .ZN(n8) );
  NOR2_X1 U97 ( .A1(n22), .A2(n83), .ZN(n59) );
  NOR2_X1 U98 ( .A1(n83), .A2(n81), .ZN(n47) );
  NOR2_X1 U99 ( .A1(n6), .A2(n83), .ZN(n41) );
  NAND2_X1 U100 ( .A1(n69), .A2(n70), .ZN(n22) );
  NAND3_X1 U101 ( .A1(n71), .A2(n36), .A3(n80), .ZN(n70) );
  NOR3_X1 U102 ( .A1(n12), .A2(n77), .A3(n6), .ZN(n33) );
  NOR4_X1 U103 ( .A1(G0), .A2(n37), .A3(n38), .A4(n39), .ZN(G44) );
  NOR2_X1 U104 ( .A1(n76), .A2(n79), .ZN(n38) );
  NOR3_X1 U105 ( .A1(n1), .A2(n79), .A3(n82), .ZN(n37) );
  NOR3_X1 U106 ( .A1(n17), .A2(n40), .A3(n13), .ZN(n39) );
  NOR4_X1 U107 ( .A1(G0), .A2(n45), .A3(n46), .A4(n2), .ZN(G34) );
  NOR2_X1 U108 ( .A1(n10), .A2(n3), .ZN(n45) );
  NOR4_X1 U109 ( .A1(n4), .A2(n30), .A3(n29), .A4(n31), .ZN(G86) );
  NOR2_X1 U110 ( .A1(n79), .A2(G66), .ZN(n31) );
  NOR2_X1 U111 ( .A1(n13), .A2(n11), .ZN(n30) );
  NOR4_X1 U112 ( .A1(n42), .A2(n43), .A3(G0), .A4(n41), .ZN(G39) );
  NOR2_X1 U113 ( .A1(n82), .A2(n44), .ZN(n43) );
  NOR2_X1 U114 ( .A1(n2), .A2(n11), .ZN(n42) );
  NOR2_X1 U115 ( .A1(n79), .A2(n80), .ZN(n28) );
  NOR2_X1 U116 ( .A1(n16), .A2(n81), .ZN(n36) );
  NOR2_X1 U117 ( .A1(n13), .A2(n82), .ZN(n71) );
  NAND3_X1 U118 ( .A1(n81), .A2(n13), .A3(n29), .ZN(n21) );
  NOR2_X1 U119 ( .A1(n82), .A2(n1), .ZN(n40) );
  NOR2_X1 U120 ( .A1(n79), .A2(n6), .ZN(n68) );
  NOR3_X1 U121 ( .A1(n48), .A2(n47), .A3(n49), .ZN(G30) );
  NOR2_X1 U122 ( .A1(n7), .A2(n3), .ZN(n49) );
  NOR2_X1 U123 ( .A1(n50), .A2(G29), .ZN(n48) );
  NOR2_X1 U124 ( .A1(G0), .A2(n51), .ZN(n50) );
  NOR2_X1 U125 ( .A1(n82), .A2(G132), .ZN(n63) );
  NOR2_X1 U126 ( .A1(n81), .A2(n9), .ZN(n64) );
  NOR2_X1 U127 ( .A1(n3), .A2(G0), .ZN(G29) );
  NOR2_X1 U128 ( .A1(n82), .A2(n10), .ZN(n51) );
  NOR2_X1 U129 ( .A1(n73), .A2(n79), .ZN(n26) );
  NOR3_X1 U130 ( .A1(n23), .A2(n24), .A3(n25), .ZN(G92) );
  NOR2_X1 U131 ( .A1(n26), .A2(n82), .ZN(n25) );
  NOR3_X1 U132 ( .A1(n13), .A2(n80), .A3(n81), .ZN(n24) );
  NAND3_X1 U133 ( .A1(n21), .A2(n22), .A3(n27), .ZN(n23) );
  NOR3_X1 U134 ( .A1(n56), .A2(n57), .A3(n58), .ZN(G113) );
  NOR2_X1 U135 ( .A1(n79), .A2(G133), .ZN(n58) );
  NOR2_X1 U136 ( .A1(n13), .A2(n7), .ZN(n57) );
  NAND3_X1 U137 ( .A1(n9), .A2(n22), .A3(n12), .ZN(n56) );
  NOR3_X1 U138 ( .A1(n65), .A2(n59), .A3(n66), .ZN(G102) );
  AND4_X1 U139 ( .A1(n13), .A2(n11), .A3(n22), .A4(n78), .ZN(n66) );
  NOR4_X1 U140 ( .A1(n4), .A2(n67), .A3(n68), .A4(n11), .ZN(n65) );
  NOR2_X1 U141 ( .A1(n78), .A2(n8), .ZN(n67) );
  NOR3_X1 U142 ( .A1(G0), .A2(n52), .A3(n53), .ZN(G125) );
  AND2_X1 U143 ( .A1(n17), .A2(G1), .ZN(n53) );
  NOR2_X1 U144 ( .A1(G1), .A2(n17), .ZN(n52) );
  NOR3_X1 U145 ( .A1(G0), .A2(n54), .A3(n55), .ZN(G119) );
  AND2_X1 U146 ( .A1(n16), .A2(G2), .ZN(n55) );
  NOR2_X1 U147 ( .A1(G2), .A2(n16), .ZN(n54) );
  NOR3_X1 U148 ( .A1(n18), .A2(n19), .A3(n20), .ZN(G98) );
  NOR2_X1 U149 ( .A1(n82), .A2(G117), .ZN(n19) );
  NOR2_X1 U150 ( .A1(G117), .A2(n8), .ZN(n20) );
  NAND3_X1 U151 ( .A1(n21), .A2(n22), .A3(n12), .ZN(n18) );
  NAND2_X1 U152 ( .A1(n73), .A2(n28), .ZN(n27) );
  NOR2_X1 U153 ( .A1(n59), .A2(n60), .ZN(G107) );
  NOR2_X1 U154 ( .A1(n61), .A2(n4), .ZN(n60) );
  NOR4_X1 U155 ( .A1(n79), .A2(n62), .A3(n63), .A4(n64), .ZN(n61) );
  NOR2_X1 U156 ( .A1(n80), .A2(G132), .ZN(n62) );
  NOR2_X1 U157 ( .A1(G0), .A2(n32), .ZN(G56) );
  NOR2_X1 U158 ( .A1(n33), .A2(n34), .ZN(n32) );
  NOR2_X1 U159 ( .A1(n72), .A2(n35), .ZN(n34) );
  AND4_X1 U160 ( .A1(n11), .A2(n79), .A3(n36), .A4(n80), .ZN(n35) );
endmodule

