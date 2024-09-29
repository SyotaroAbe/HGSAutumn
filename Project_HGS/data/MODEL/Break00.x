xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 48;
 -12.44667;11.10925;-12.91816;,
 0.89046;14.26497;-13.72833;,
 0.00000;0.00000;-17.92159;,
 -13.68245;1.84634;-14.07076;,
 10.91594;12.96555;-13.83130;,
 16.75584;0.05957;-14.98404;,
 0.41794;-12.89329;-17.73989;,
 -9.86150;-10.74902;-12.43539;,
 12.09541;-10.83468;-13.10705;,
 10.91594;12.96555;-13.83130;,
 12.72005;13.52060;-2.33257;,
 17.92159;0.00000;0.00000;,
 16.75584;0.05957;-14.98404;,
 11.89340;9.28620;7.51449;,
 16.50242;-0.44085;12.09462;,
 14.85563;-14.38759;-2.60011;,
 12.09541;-10.83468;-13.10705;,
 11.72747;-9.73457;11.35009;,
 11.89340;9.28620;7.51449;,
 1.95668;11.36772;15.60435;,
 0.00000;0.00000;17.92159;,
 16.50242;-0.44085;12.09462;,
 -10.65926;13.75379;8.64949;,
 -11.00876;1.30494;16.31332;,
 -1.21338;-11.98475;17.13581;,
 11.72747;-9.73457;11.35009;,
 -13.29021;-6.73741;15.97330;,
 -10.65926;13.75379;8.64949;,
 -14.46171;15.42764;2.93668;,
 -17.92159;0.00000;0.00000;,
 -11.00876;1.30494;16.31332;,
 -12.44667;11.10925;-12.91816;,
 -13.68245;1.84634;-14.07076;,
 -16.91201;-14.11816;0.52790;,
 -13.29021;-6.73741;15.97330;,
 -9.86150;-10.74902;-12.43539;,
 0.00000;17.92159;0.00000;,
 -14.46171;15.42764;2.93668;,
 12.72005;13.52060;-2.33257;,
 0.89046;14.26497;-13.72833;,
 -12.44667;11.10925;-12.91816;,
 10.91594;12.96555;-13.83130;,
 -16.91201;-14.11816;0.52790;,
 0.00000;-17.92159;-0.00000;,
 14.85563;-14.38759;-2.60011;,
 -9.86150;-10.74902;-12.43539;,
 0.41794;-12.89329;-17.73989;,
 12.09541;-10.83468;-13.10705;;
 
 24;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;3,2,6,7;,
 4;2,5,8,6;,
 4;9,10,11,12;,
 4;10,13,14,11;,
 4;12,11,15,16;,
 4;11,14,17,15;,
 4;18,19,20,21;,
 4;19,22,23,20;,
 4;21,20,24,25;,
 4;20,23,26,24;,
 4;27,28,29,30;,
 4;28,31,32,29;,
 4;30,29,33,34;,
 4;29,32,35,33;,
 4;27,19,36,37;,
 4;19,13,38,36;,
 4;37,36,39,40;,
 4;36,38,41,39;,
 4;42,43,24,34;,
 4;43,44,17,24;,
 4;45,46,43,42;,
 4;46,47,44,43;;
 
 MeshMaterialList {
  1;
  24;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  37;
  -0.239205;0.664563;-0.707910;,
  -0.045146;0.224063;-0.973529;,
  -0.538767;-0.036039;-0.841684;,
  -0.051806;0.053426;-0.997227;,
  -0.602519;-0.479859;-0.637736;,
  -0.057130;-0.126949;-0.990263;,
  0.098563;0.222974;-0.969829;,
  0.672757;0.736165;0.073889;,
  0.188848;0.052207;-0.980618;,
  0.998698;0.047608;0.018339;,
  0.272065;-0.120513;-0.954703;,
  0.691883;-0.721904;0.012342;,
  0.648924;0.577232;0.495682;,
  0.166305;0.697815;0.696705;,
  0.782495;0.057529;0.619994;,
  0.133441;0.125964;0.983019;,
  0.612640;-0.553551;0.564140;,
  0.123903;-0.102027;0.987035;,
  -0.458939;0.571785;0.680027;,
  -0.971959;0.196554;0.129083;,
  -0.622749;0.169637;0.763811;,
  -0.996653;0.071091;0.040367;,
  -0.131620;-0.026919;0.990935;,
  -0.997015;-0.058156;-0.050779;,
  0.082516;0.993499;0.078430;,
  -0.018753;-0.999251;0.033859;,
  0.631486;0.760777;-0.149813;,
  0.985356;0.055510;-0.161224;,
  0.662610;-0.693212;-0.283558;,
  -0.952031;0.204762;-0.227396;,
  -0.945420;0.091542;0.312732;,
  -0.156416;0.986517;0.048147;,
  -0.011584;0.976054;-0.217217;,
  -0.304049;-0.951627;0.044268;,
  -0.004335;-0.922393;0.386229;,
  -0.297540;-0.870062;0.393016;,
  -0.030565;-0.947765;-0.317502;;
  24;
  4;0,1,3,2;,
  4;1,6,8,3;,
  4;2,3,5,4;,
  4;3,8,10,5;,
  4;26,7,9,27;,
  4;7,12,14,9;,
  4;27,9,11,28;,
  4;9,14,16,11;,
  4;12,13,15,14;,
  4;13,18,20,15;,
  4;14,15,17,16;,
  4;15,20,22,17;,
  4;18,19,21,20;,
  4;19,29,29,21;,
  4;20,21,23,30;,
  4;21,2,4,23;,
  4;18,13,24,31;,
  4;13,12,7,24;,
  4;31,24,32,0;,
  4;24,7,26,32;,
  4;33,25,34,35;,
  4;25,11,16,34;,
  4;4,36,25,33;,
  4;36,28,11,25;;
 }
 MeshTextureCoords {
  48;
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.500000;,
  0.500000;0.500000;,
  1.000000;0.500000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  1.000000;0.000000;;
 }
}
