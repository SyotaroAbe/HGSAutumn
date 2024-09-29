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
 103;
 -0.11089;24.25822;-1.57177;,
 1.25030;24.25822;-0.78588;,
 1.25030;13.34729;-0.78588;,
 -0.11089;13.34729;-1.57177;,
 1.25030;24.25822;0.78588;,
 1.25030;13.34729;0.78588;,
 -0.11089;24.25822;1.57177;,
 -0.11089;13.34729;1.57177;,
 -1.47209;24.25822;0.78588;,
 -1.47209;13.34729;0.78588;,
 -1.47209;24.25822;-0.78588;,
 -1.47209;13.34729;-0.78588;,
 -0.11089;24.25822;-1.57177;,
 -0.11089;13.34729;-1.57177;,
 3.67322;9.31770;-2.18476;,
 -0.11089;9.31770;-4.36950;,
 3.67322;9.31770;2.18476;,
 -0.11089;9.31770;4.36950;,
 -3.89500;9.31770;2.18476;,
 -3.89500;9.31770;-2.18476;,
 -0.11089;9.31770;-4.36950;,
 4.48574;5.46419;-2.65387;,
 -0.11089;5.46419;-5.30773;,
 4.48574;5.46419;2.65387;,
 -0.11089;5.46419;5.30773;,
 -4.70753;5.46419;2.65387;,
 -4.70753;5.46419;-2.65387;,
 -0.11089;5.46419;-5.30773;,
 3.96717;2.73081;-2.35447;,
 -0.11089;2.73081;-4.70895;,
 3.96717;2.73081;2.35447;,
 -0.11089;2.73081;4.70895;,
 -4.18896;2.73081;2.35447;,
 -4.18896;2.73081;-2.35447;,
 -0.11089;2.73081;-4.70895;,
 2.92758;-0.14162;-1.75427;,
 -0.11089;-0.14162;-3.50853;,
 2.92758;-0.14162;1.75427;,
 -0.11089;-0.14162;3.50853;,
 -3.14938;-0.14162;1.75427;,
 -3.14938;-0.14162;-1.75427;,
 -0.11089;-0.14162;-3.50853;,
 -0.11089;24.25822;0.00000;,
 -0.11089;24.25822;0.00000;,
 -0.11089;24.25822;0.00000;,
 -0.11089;24.25822;0.00000;,
 -0.11089;24.25822;0.00000;,
 -0.11089;24.25822;0.00000;,
 -0.11089;-0.14162;0.00000;,
 -0.11089;-0.14162;0.00000;,
 -0.11089;-0.14162;0.00000;,
 -0.11089;-0.14162;0.00000;,
 -0.11089;-0.14162;0.00000;,
 -0.11089;-0.14162;0.00000;,
 -0.00000;24.16003;-1.46767;,
 -0.00000;24.48422;-1.55940;,
 -1.35048;24.48422;-0.77970;,
 -1.27104;24.16003;-0.73383;,
 -0.00000;24.48422;-1.74285;,
 -1.50936;24.48422;-0.87143;,
 -0.00000;24.16003;-1.83459;,
 -1.58880;24.16003;-0.91729;,
 -0.00000;23.83584;-1.74285;,
 -1.50936;23.83584;-0.87143;,
 -0.00000;23.83584;-1.55940;,
 -1.35048;23.83584;-0.77970;,
 -0.00000;24.16003;-1.46767;,
 -1.27104;24.16003;-0.73383;,
 -1.35048;24.48422;0.77970;,
 -1.27104;24.16003;0.73383;,
 -1.50936;24.48422;0.87143;,
 -1.58880;24.16003;0.91729;,
 -1.50936;23.83584;0.87143;,
 -1.35048;23.83584;0.77970;,
 -1.27104;24.16003;0.73383;,
 0.00000;24.48422;1.55940;,
 0.00000;24.16003;1.46767;,
 0.00000;24.48422;1.74285;,
 0.00000;24.16003;1.83459;,
 0.00000;23.83584;1.74285;,
 0.00000;23.83584;1.55940;,
 0.00000;24.16003;1.46767;,
 1.35048;24.48422;0.77970;,
 1.27104;24.16003;0.73383;,
 1.50936;24.48422;0.87143;,
 1.58880;24.16003;0.91729;,
 1.50936;23.83584;0.87143;,
 1.35048;23.83584;0.77970;,
 1.27104;24.16003;0.73383;,
 1.35048;24.48422;-0.77970;,
 1.27104;24.16003;-0.73383;,
 1.50936;24.48422;-0.87143;,
 1.58880;24.16003;-0.91729;,
 1.50936;23.83584;-0.87143;,
 1.35048;23.83584;-0.77970;,
 1.27104;24.16003;-0.73383;,
 -0.00000;24.48422;-1.55940;,
 -0.00000;24.16003;-1.46767;,
 -0.00000;24.48422;-1.74285;,
 -0.00000;24.16003;-1.83459;,
 -0.00000;23.83584;-1.74285;,
 -0.00000;23.83584;-1.55940;,
 -0.00000;24.16003;-1.46767;;
 
 78;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;3,2,14,15;,
 4;2,5,16,14;,
 4;5,7,17,16;,
 4;7,9,18,17;,
 4;9,11,19,18;,
 4;11,13,20,19;,
 4;15,14,21,22;,
 4;14,16,23,21;,
 4;16,17,24,23;,
 4;17,18,25,24;,
 4;18,19,26,25;,
 4;19,20,27,26;,
 4;22,21,28,29;,
 4;21,23,30,28;,
 4;23,24,31,30;,
 4;24,25,32,31;,
 4;25,26,33,32;,
 4;26,27,34,33;,
 4;29,28,35,36;,
 4;28,30,37,35;,
 4;30,31,38,37;,
 4;31,32,39,38;,
 4;32,33,40,39;,
 4;33,34,41,40;,
 3;42,1,0;,
 3;43,4,1;,
 3;44,6,4;,
 3;45,8,6;,
 3;46,10,8;,
 3;47,12,10;,
 3;48,36,35;,
 3;49,35,37;,
 3;50,37,38;,
 3;51,38,39;,
 3;52,39,40;,
 3;53,40,41;,
 4;54,55,56,57;,
 4;55,58,59,56;,
 4;58,60,61,59;,
 4;60,62,63,61;,
 4;62,64,65,63;,
 4;64,66,67,65;,
 4;57,56,68,69;,
 4;56,59,70,68;,
 4;59,61,71,70;,
 4;61,63,72,71;,
 4;63,65,73,72;,
 4;65,67,74,73;,
 4;69,68,75,76;,
 4;68,70,77,75;,
 4;70,71,78,77;,
 4;71,72,79,78;,
 4;72,73,80,79;,
 4;73,74,81,80;,
 4;76,75,82,83;,
 4;75,77,84,82;,
 4;77,78,85,84;,
 4;78,79,86,85;,
 4;79,80,87,86;,
 4;80,81,88,87;,
 4;83,82,89,90;,
 4;82,84,91,89;,
 4;84,85,92,91;,
 4;85,86,93,92;,
 4;86,87,94,93;,
 4;87,88,95,94;,
 4;90,89,96,97;,
 4;89,91,98,96;,
 4;91,92,99,98;,
 4;92,93,100,99;,
 4;93,94,101,100;,
 4;94,95,102,101;;
 
 MeshMaterialList {
  2;
  78;
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
  1,
  1,
  1,
  1,
  1,
  1,
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
   0.624314;0.737255;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.730980;0.730980;0.730980;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  72;
  0.000000;1.000000;0.000000;,
  0.500003;0.000000;-0.866024;,
  1.000000;0.000000;0.000000;,
  0.500003;0.000000;0.866024;,
  -0.500001;0.000000;0.866025;,
  -1.000000;0.000000;0.000000;,
  0.191229;0.394160;-0.898927;,
  0.682881;0.394160;-0.615071;,
  0.874107;0.394160;0.283855;,
  0.191229;0.394160;0.898927;,
  -0.682880;0.394160;0.615071;,
  -0.874108;0.394160;-0.283855;,
  0.000000;0.413366;-0.910565;,
  0.788572;0.413366;-0.455282;,
  0.788572;0.413366;0.455282;,
  0.000000;0.413366;0.910565;,
  -0.788572;0.413366;0.455283;,
  -0.788572;0.413366;-0.455283;,
  0.000000;0.011733;-0.999931;,
  0.865966;0.011732;-0.499966;,
  0.865966;0.011732;0.499966;,
  0.000000;0.011733;0.999931;,
  -0.865966;0.011733;0.499966;,
  -0.865966;0.011733;-0.499966;,
  0.000000;-0.301580;-0.953441;,
  0.825704;-0.301580;-0.476720;,
  0.825704;-0.301580;0.476720;,
  0.000000;-0.301580;0.953441;,
  -0.825704;-0.301580;0.476721;,
  -0.825704;-0.301580;-0.476721;,
  0.000000;-0.385592;-0.922669;,
  0.799055;-0.385592;-0.461334;,
  0.799055;-0.385592;0.461334;,
  0.000000;-0.385592;0.922669;,
  -0.799055;-0.385592;0.461335;,
  -0.799055;-0.385592;-0.461335;,
  0.000000;-1.000000;-0.000000;,
  0.500001;0.000000;0.866025;,
  0.000000;0.272259;0.962224;,
  -0.500000;0.000000;-0.866026;,
  0.000000;-0.272264;-0.962223;,
  0.833311;0.272259;0.481112;,
  -0.833310;-0.272262;-0.481111;,
  1.000000;0.000000;-0.000000;,
  0.833310;0.272260;-0.481112;,
  -0.833310;-0.272262;0.481111;,
  0.500000;0.000000;-0.866025;,
  -0.000000;0.272260;-0.962224;,
  -0.500000;0.000000;0.866026;,
  0.000000;-0.272264;0.962223;,
  -0.500001;0.000000;-0.866025;,
  -0.833311;0.272259;-0.481112;,
  0.500000;0.000000;0.866025;,
  0.833310;-0.272261;0.481111;,
  -1.000000;0.000000;0.000000;,
  -0.833310;0.272259;0.481112;,
  0.833310;-0.272261;-0.481112;,
  -0.500001;0.000000;-0.866025;,
  0.000000;0.272264;-0.962223;,
  -0.833310;0.272262;-0.481111;,
  0.000000;-0.272259;0.962224;,
  0.833311;-0.272259;0.481112;,
  -0.833310;0.272262;0.481111;,
  0.833310;-0.272260;-0.481112;,
  0.000000;0.272264;0.962223;,
  -0.000000;-0.272260;-0.962224;,
  0.833310;0.272261;0.481111;,
  -0.833311;-0.272259;-0.481112;,
  0.833310;0.272261;-0.481112;,
  -0.833310;-0.272259;0.481112;,
  -0.500000;0.000000;0.866025;,
  0.500000;0.000000;-0.866026;;
  78;
  4;1,1,7,6;,
  4;2,2,8,2;,
  4;3,3,9,3;,
  4;4,4,10,4;,
  4;5,5,11,5;,
  4;57,57,57,57;,
  4;6,7,13,12;,
  4;7,8,14,13;,
  4;8,9,15,14;,
  4;9,10,16,15;,
  4;10,11,17,16;,
  4;11,6,12,17;,
  4;12,13,19,18;,
  4;13,14,20,19;,
  4;14,15,21,20;,
  4;15,16,22,21;,
  4;16,17,23,22;,
  4;17,12,18,23;,
  4;18,19,25,24;,
  4;19,20,26,25;,
  4;20,21,27,26;,
  4;21,22,28,27;,
  4;22,23,29,28;,
  4;23,18,24,29;,
  4;24,25,31,30;,
  4;25,26,32,31;,
  4;26,27,33,32;,
  4;27,28,34,33;,
  4;28,29,35,34;,
  4;29,24,30,35;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;36,36,36;,
  3;36,36,36;,
  3;36,36,36;,
  3;36,36,36;,
  3;36,36,36;,
  3;36,36,36;,
  4;37,38,41,37;,
  4;0,0,0,0;,
  4;58,39,39,59;,
  4;39,40,42,39;,
  4;36,36,36,36;,
  4;60,37,37,61;,
  4;43,41,44,43;,
  4;0,0,0,0;,
  4;59,5,5,62;,
  4;5,42,45,5;,
  4;36,36,36,36;,
  4;61,43,43,63;,
  4;46,44,47,46;,
  4;0,0,0,0;,
  4;62,48,48,64;,
  4;48,45,49,48;,
  4;36,36,36,36;,
  4;63,46,46,65;,
  4;50,47,51,50;,
  4;0,0,0,0;,
  4;64,52,52,66;,
  4;52,49,53,52;,
  4;36,36,36,36;,
  4;65,50,50,67;,
  4;54,51,55,54;,
  4;0,0,0,0;,
  4;66,2,2,68;,
  4;2,53,56,2;,
  4;36,36,36,36;,
  4;67,54,54,69;,
  4;70,55,38,70;,
  4;0,0,0,0;,
  4;68,71,71,58;,
  4;71,56,40,71;,
  4;36,36,36,36;,
  4;69,70,70,60;;
 }
 MeshTextureCoords {
  103;
  0.000000;0.000000;,
  0.166670;0.000000;,
  0.166670;0.200000;,
  0.000000;0.200000;,
  0.333330;0.000000;,
  0.333330;0.200000;,
  0.500000;0.000000;,
  0.500000;0.200000;,
  0.666670;0.000000;,
  0.666670;0.200000;,
  0.833330;0.000000;,
  0.833330;0.200000;,
  1.000000;0.000000;,
  1.000000;0.200000;,
  0.166670;0.400000;,
  0.000000;0.400000;,
  0.333330;0.400000;,
  0.500000;0.400000;,
  0.666670;0.400000;,
  0.833330;0.400000;,
  1.000000;0.400000;,
  0.166670;0.600000;,
  0.000000;0.600000;,
  0.333330;0.600000;,
  0.500000;0.600000;,
  0.666670;0.600000;,
  0.833330;0.600000;,
  1.000000;0.600000;,
  0.166670;0.800000;,
  0.000000;0.800000;,
  0.333330;0.800000;,
  0.500000;0.800000;,
  0.666670;0.800000;,
  0.833330;0.800000;,
  1.000000;0.800000;,
  0.166670;1.000000;,
  0.000000;1.000000;,
  0.333330;1.000000;,
  0.500000;1.000000;,
  0.666670;1.000000;,
  0.833330;1.000000;,
  1.000000;1.000000;,
  0.083330;0.000000;,
  0.250000;0.000000;,
  0.416670;0.000000;,
  0.583330;0.000000;,
  0.750000;0.000000;,
  0.916670;0.000000;,
  0.083330;1.000000;,
  0.250000;1.000000;,
  0.416670;1.000000;,
  0.583330;1.000000;,
  0.750000;1.000000;,
  0.916670;1.000000;,
  0.000000;0.000000;,
  0.000000;0.166667;,
  0.166667;0.166667;,
  0.166667;0.000000;,
  0.000000;0.333333;,
  0.166667;0.333333;,
  0.000000;0.500000;,
  0.166667;0.500000;,
  0.000000;0.666667;,
  0.166667;0.666667;,
  0.000000;0.833333;,
  0.166667;0.833333;,
  0.000000;1.000000;,
  0.166667;1.000000;,
  0.333333;0.166667;,
  0.333333;0.000000;,
  0.333333;0.333333;,
  0.333333;0.500000;,
  0.333333;0.666667;,
  0.333333;0.833333;,
  0.333333;1.000000;,
  0.500000;0.166667;,
  0.500000;0.000000;,
  0.500000;0.333333;,
  0.500000;0.500000;,
  0.500000;0.666667;,
  0.500000;0.833333;,
  0.500000;1.000000;,
  0.666667;0.166667;,
  0.666667;0.000000;,
  0.666667;0.333333;,
  0.666667;0.500000;,
  0.666667;0.666667;,
  0.666667;0.833333;,
  0.666667;1.000000;,
  0.833333;0.166667;,
  0.833333;0.000000;,
  0.833333;0.333333;,
  0.833333;0.500000;,
  0.833333;0.666667;,
  0.833333;0.833333;,
  0.833333;1.000000;,
  1.000000;0.166667;,
  1.000000;0.000000;,
  1.000000;0.333333;,
  1.000000;0.500000;,
  1.000000;0.666667;,
  1.000000;0.833333;,
  1.000000;1.000000;;
 }
}
