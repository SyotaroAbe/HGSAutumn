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
 78;
 -15.60000;66.00000;-0.60000;,
 15.60000;66.00000;-0.60000;,
 15.60000;1.20000;-0.60000;,
 -15.60000;1.20000;-0.60000;,
 15.60000;66.00000;0.60000;,
 -15.60000;66.00000;0.60000;,
 -15.60000;1.20000;0.60000;,
 15.60000;1.20000;0.60000;,
 12.99360;32.41619;0.73480;,
 13.81575;32.07565;0.73480;,
 13.81575;32.07565;-0.73487;,
 12.99360;32.41619;-0.73487;,
 13.81575;32.07565;0.73480;,
 14.15629;31.25351;0.73480;,
 14.15629;31.25351;-0.73487;,
 13.81575;32.07565;-0.73487;,
 13.81575;30.43135;0.73480;,
 13.81575;30.43135;-0.73487;,
 12.99360;30.09081;0.73480;,
 12.99360;30.09081;-0.73487;,
 12.17146;30.43135;0.73480;,
 12.17146;30.43135;-0.73487;,
 11.83091;31.25351;0.73480;,
 11.83091;31.25351;-0.73487;,
 12.17146;32.07565;0.73480;,
 12.17146;32.07565;-0.73487;,
 12.99360;32.41619;0.73480;,
 12.99360;32.41619;-0.73487;,
 12.99360;31.25351;0.62640;,
 12.99360;32.41619;0.73480;,
 12.99360;31.25351;0.62640;,
 12.99360;31.25351;0.62640;,
 12.99360;31.25351;0.62640;,
 12.99360;31.25351;0.62640;,
 12.99360;31.25351;0.62640;,
 12.99360;31.25351;0.62640;,
 12.99360;31.25351;0.62640;,
 12.99360;31.25351;-0.62646;,
 12.99360;32.41619;-0.73487;,
 12.99360;31.25351;-0.62646;,
 12.99360;31.25351;-0.62646;,
 12.99360;31.25351;-0.62646;,
 12.99360;31.25351;-0.62646;,
 12.99360;31.25351;-0.62646;,
 12.99360;31.25351;-0.62646;,
 12.99360;31.25351;-0.62646;,
 16.80000;67.20000;0.60000;,
 -16.80000;67.20000;0.60000;,
 -15.60000;66.00000;0.60000;,
 15.60000;66.00000;0.60000;,
 16.80000;67.20000;-0.60000;,
 16.80000;67.20000;0.60000;,
 -16.80000;67.20000;-0.60000;,
 16.80000;67.20000;-0.60000;,
 15.60000;66.00000;-0.60000;,
 -15.60000;66.00000;-0.60000;,
 -16.80000;67.20000;0.60000;,
 -16.80000;67.20000;-0.60000;,
 16.80000;0.00000;0.60000;,
 15.60000;1.20000;0.60000;,
 16.80000;0.00000;-0.60000;,
 16.80000;0.00000;0.60000;,
 16.80000;67.20000;-0.60000;,
 16.80000;0.00000;-0.60000;,
 15.60000;1.20000;-0.60000;,
 15.60000;66.00000;-0.60000;,
 -16.80000;0.00000;-0.60000;,
 -16.80000;67.20000;-0.60000;,
 -15.60000;66.00000;-0.60000;,
 -15.60000;1.20000;-0.60000;,
 -16.80000;0.00000;0.60000;,
 -16.80000;0.00000;-0.60000;,
 -16.80000;0.00000;0.60000;,
 -15.60000;1.20000;0.60000;,
 16.80000;0.00000;-0.60000;,
 -16.80000;0.00000;-0.60000;,
 -15.60000;1.20000;-0.60000;,
 15.60000;1.20000;-0.60000;;
 
 46;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;13,16,17,14;,
 4;16,18,19,17;,
 4;18,20,21,19;,
 4;20,22,23,21;,
 4;22,24,25,23;,
 4;24,26,27,25;,
 3;28,12,29;,
 3;30,13,12;,
 3;31,16,13;,
 3;32,18,16;,
 3;33,20,18;,
 3;34,22,20;,
 3;35,24,22;,
 3;36,26,24;,
 3;37,38,15;,
 3;39,15,14;,
 3;40,14,17;,
 3;41,17,19;,
 3;42,19,21;,
 3;43,21,23;,
 3;44,23,25;,
 3;45,25,27;,
 4;46,47,48,49;,
 4;50,51,4,1;,
 4;52,53,54,55;,
 4;56,57,0,5;,
 4;47,46,53,52;,
 4;51,50,1,4;,
 4;58,46,49,59;,
 4;60,61,7,2;,
 4;62,63,64,65;,
 4;62,46,58,63;,
 4;57,56,5,0;,
 4;66,67,68,69;,
 4;70,71,3,6;,
 4;47,72,73,48;,
 4;47,67,66,72;,
 4;74,75,76,77;,
 4;61,60,2,7;,
 4;72,58,59,73;,
 4;71,70,6,3;,
 4;75,74,58,72;;
 
 MeshMaterialList {
  2;
  46;
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  0,
  1,
  0,
  1,
  0,
  1,
  1,
  0,
  1,
  0,
  1,
  1,
  1,
  0,
  1,
  0,
  1;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\MapObj\\fusuma.jpeg";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  40;
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;-0.000001;1.000000;,
  -0.000000;1.000000;0.000000;,
  0.707102;0.707112;0.000000;,
  1.000000;0.000003;0.000000;,
  0.707109;-0.707105;-0.000000;,
  -0.000000;-1.000000;0.000000;,
  -0.707109;-0.707105;0.000000;,
  -1.000000;0.000003;0.000000;,
  -0.707101;0.707112;0.000000;,
  0.000000;-0.000001;-1.000000;,
  0.923880;-0.382683;-0.000000;,
  -0.382683;-0.923880;0.000000;,
  0.382683;-0.923880;-0.000000;,
  -0.065638;-0.065639;0.995682;,
  0.000000;-0.092827;0.995682;,
  -0.092826;-0.000000;0.995682;,
  -0.065638;0.065637;0.995682;,
  0.000000;0.092825;0.995682;,
  0.065638;0.065637;0.995682;,
  0.092826;-0.000000;0.995682;,
  0.065638;-0.065639;0.995682;,
  0.000000;-0.092837;-0.995681;,
  -0.065645;-0.065646;-0.995681;,
  -0.092836;-0.000000;-0.995681;,
  -0.065645;0.065644;-0.995681;,
  0.000000;0.092835;-0.995681;,
  0.065645;0.065645;-0.995681;,
  0.092836;-0.000000;-0.995681;,
  0.065645;-0.065646;-0.995681;,
  0.707107;-0.707107;-0.000000;,
  -0.923880;-0.382683;0.000000;,
  -0.707107;-0.707107;0.000000;,
  0.382683;0.923880;0.000000;,
  -0.382683;0.923880;0.000000;,
  -0.707107;0.707107;0.000000;,
  0.923880;0.382683;0.000000;,
  0.707107;0.707107;0.000000;,
  -0.923880;0.382683;0.000000;;
  46;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;3,4,4,3;,
  4;4,5,5,4;,
  4;5,6,6,5;,
  4;6,7,7,6;,
  4;7,8,8,7;,
  4;8,9,9,8;,
  4;9,10,10,9;,
  4;10,3,3,10;,
  3;2,15,16;,
  3;2,17,15;,
  3;2,18,17;,
  3;2,19,18;,
  3;2,20,19;,
  3;2,21,20;,
  3;2,22,21;,
  3;2,16,22;,
  3;11,23,24;,
  3;11,24,25;,
  3;11,25,26;,
  3;11,26,27;,
  3;11,27,28;,
  3;11,28,29;,
  3;11,29,30;,
  3;11,30,23;,
  4;1,1,1,1;,
  4;12,12,31,31;,
  4;0,0,0,0;,
  4;32,32,33,33;,
  4;34,35,35,34;,
  4;35,35,36,36;,
  4;1,1,1,1;,
  4;13,13,33,33;,
  4;0,0,0,0;,
  4;12,12,37,37;,
  4;34,34,38,38;,
  4;0,0,0,0;,
  4;14,14,31,31;,
  4;1,1,1,1;,
  4;32,32,39,39;,
  4;0,0,0,0;,
  4;37,37,38,38;,
  4;1,1,1,1;,
  4;39,39,36,36;,
  4;14,13,13,14;;
 }
 MeshTextureCoords {
  78;
  -0.377281;-0.201535;,
  1.121696;-0.201535;,
  1.121696;0.981504;,
  -0.377281;0.981504;,
  1.121696;-0.201535;,
  -0.377281;-0.201535;,
  -0.377281;0.981504;,
  1.121696;0.981504;,
  0.996474;0.411597;,
  1.035973;0.417814;,
  1.035973;0.417814;,
  0.996474;0.411597;,
  0.125000;0.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.125000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.062500;0.000000;,
  0.000000;0.000000;,
  0.187500;0.000000;,
  0.312500;0.000000;,
  0.437500;0.000000;,
  0.562500;0.000000;,
  0.687500;0.000000;,
  0.812500;0.000000;,
  0.937500;0.000000;,
  0.062500;1.000000;,
  0.000000;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.179349;-0.223443;,
  1.179349;-0.223443;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  -0.434934;-0.223443;,
  -0.434934;-0.223443;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.179349;1.003412;,
  1.179349;1.003412;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  -0.434934;1.003412;,
  -0.434934;1.003412;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;;
 }
}
