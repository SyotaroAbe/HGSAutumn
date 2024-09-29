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
 186;
 0.55118;3.80544;0.58445;,
 0.85843;3.80300;0.58445;,
 0.85843;3.78266;0.35105;,
 0.55118;3.78511;0.35105;,
 1.70070;3.88163;0.58445;,
 1.70070;3.86131;0.35105;,
 0.58261;3.91929;0.99417;,
 0.85843;3.92688;0.99166;,
 1.51149;4.01745;0.91814;,
 0.44929;0.63842;4.07888;,
 0.88097;0.63842;4.09357;,
 0.97744;1.48011;2.93988;,
 0.58473;1.48011;2.89375;,
 2.33047;0.63842;3.90023;,
 1.98195;1.48011;2.70923;,
 0.41337;-0.07860;2.61779;,
 0.74856;-0.07845;2.61885;,
 0.75098;0.03807;3.58865;,
 0.44595;0.03799;3.57778;,
 1.96503;-0.07773;2.62253;,
 1.77421;0.03837;3.45491;,
 0.38861;-0.19412;1.88090;,
 0.74635;-0.19407;1.87368;,
 2.08732;-0.19391;2.05272;,
 2.60994;0.47069;2.69945;,
 2.21286;1.48011;1.54434;,
 2.21286;1.48011;0.80349;,
 2.79164;0.30303;1.87289;,
 -1.27741;0.63842;4.02016;,
 -0.98612;1.48011;2.70923;,
 -1.21703;1.48011;1.54434;,
 -1.50162;0.47069;2.69946;,
 -1.21703;1.48011;0.80349;,
 -1.67117;0.30303;1.67276;,
 0.85843;3.70295;-0.02224;,
 0.54949;3.72196;-0.02224;,
 1.72671;3.78178;-0.02224;,
 2.90293;0.00000;-0.02224;,
 2.45747;1.48011;-0.02224;,
 0.76484;-0.40677;0.72875;,
 2.16596;-0.40737;0.72528;,
 0.35360;-0.40659;0.72979;,
 -1.52850;1.48011;-0.02224;,
 -2.02481;0.00000;-0.02224;,
 -1.07936;2.07395;1.15745;,
 -1.07936;2.07395;0.41659;,
 2.06074;2.07395;0.41659;,
 2.06074;2.07395;1.15744;,
 1.01868;2.07395;2.24214;,
 0.64057;2.07395;2.19601;,
 -0.87191;2.07395;2.01149;,
 1.85329;2.07395;2.01149;,
 -1.12124;2.28992;-0.02224;,
 2.16433;2.28992;-0.02224;,
 -0.83968;2.83264;0.83411;,
 -0.83968;2.83264;0.22647;,
 1.89892;2.83264;0.22647;,
 1.82291;2.83264;0.83412;,
 0.92915;2.83264;1.61331;,
 0.61157;2.83264;1.57548;,
 -0.65876;2.83264;1.42413;,
 1.71799;2.83264;1.53460;,
 -0.79503;3.04861;-0.02224;,
 1.97900;3.04861;-0.02224;,
 -0.67783;3.82763;0.52973;,
 -0.67783;3.76561;0.35105;,
 -0.41533;3.96676;0.83215;,
 -0.68630;3.70047;-0.02224;,
 -1.04622;-0.19415;1.91051;,
 -1.29514;-0.40648;0.73046;,
 -0.26326;-0.40631;0.73134;,
 -0.14799;-0.19419;1.89173;,
 -0.92799;-0.07857;2.61727;,
 -0.08943;-0.07882;2.61621;,
 -0.77127;0.03801;3.53667;,
 -0.01160;0.03789;3.56148;,
 -0.19822;0.63842;4.05686;,
 -0.00434;1.48011;2.82455;,
 0.07339;2.07395;2.12682;,
 0.13519;2.83264;1.51872;,
 0.16887;3.90790;0.99794;,
 0.09030;3.80910;0.58445;,
 0.09030;3.78878;0.35105;,
 0.08607;3.75046;-0.02224;,
 0.44753;0.27880;3.79393;,
 0.80559;0.27885;3.80647;,
 2.00718;0.27906;3.64819;,
 2.23418;0.14167;2.66379;,
 2.38048;0.00425;1.98849;,
 2.47280;-0.24660;0.42834;,
 0.82393;-0.24617;0.43085;,
 0.90705;0.00000;-0.02224;,
 0.33979;-0.24604;0.43160;,
 0.32068;0.00000;-0.02224;,
 -0.55888;0.00000;-0.02224;,
 -0.38641;-0.24585;0.43272;,
 -1.59949;-0.24597;0.43208;,
 -1.30685;0.00410;1.82192;,
 -1.16735;0.14107;2.66000;,
 -0.98261;0.27880;3.74549;,
 -0.08956;0.27872;3.77513;,
 0.55118;3.78511;-0.39554;,
 0.85843;3.78266;-0.39554;,
 0.85843;3.80300;-0.62894;,
 0.55118;3.80544;-0.62894;,
 1.70070;3.86131;-0.39554;,
 1.70070;3.88163;-0.62894;,
 0.85843;3.92688;-1.03615;,
 0.58261;3.91929;-1.03866;,
 1.51149;4.01745;-0.96262;,
 0.58472;1.48011;-2.93823;,
 0.97743;1.48011;-2.98436;,
 0.88096;0.63842;-4.13805;,
 0.44929;0.63842;-4.12337;,
 1.98195;1.48011;-2.75371;,
 2.33046;0.63842;-3.94471;,
 0.44594;0.03799;-3.62227;,
 0.75098;0.03807;-3.63314;,
 0.74856;-0.07845;-2.66333;,
 0.41337;-0.07860;-2.66228;,
 1.77420;0.03837;-3.49940;,
 1.96502;-0.07773;-2.66701;,
 0.74635;-0.19407;-1.91816;,
 0.38861;-0.19412;-1.92539;,
 2.08732;-0.19391;-2.09721;,
 2.60993;0.47069;-2.74394;,
 2.21286;1.48011;-1.58882;,
 2.21286;1.48011;-0.84797;,
 2.79164;0.30303;-1.91737;,
 -1.27741;0.63842;-4.06464;,
 -1.50163;0.47069;-2.74394;,
 -1.21703;1.48011;-1.58882;,
 -0.98612;1.48011;-2.75371;,
 -1.67117;0.30303;-1.71724;,
 -1.21703;1.48011;-0.84797;,
 2.16596;-0.40737;-0.76976;,
 0.76484;-0.40677;-0.77324;,
 0.35360;-0.40659;-0.77427;,
 -1.07936;2.07395;-0.46108;,
 -1.07936;2.07395;-1.20193;,
 2.06074;2.07395;-1.20193;,
 2.06074;2.07395;-0.46108;,
 0.64057;2.07395;-2.24050;,
 1.01868;2.07395;-2.28663;,
 -0.87191;2.07395;-2.05598;,
 1.85329;2.07395;-2.05597;,
 -0.83968;2.83264;-0.27095;,
 -0.83968;2.83264;-0.87860;,
 1.82291;2.83264;-0.87860;,
 1.89892;2.83264;-0.27095;,
 0.61157;2.83264;-1.61996;,
 0.92915;2.83264;-1.65780;,
 -0.65876;2.83264;-1.46862;,
 1.71799;2.83264;-1.57909;,
 -0.67783;3.76561;-0.39554;,
 -0.67783;3.82763;-0.57421;,
 -0.41533;3.96676;-0.87664;,
 -1.04622;-0.19415;-1.95500;,
 -0.14799;-0.19419;-1.93622;,
 -0.26326;-0.40631;-0.77583;,
 -1.29514;-0.40648;-0.77494;,
 -0.92799;-0.07857;-2.66175;,
 -0.08943;-0.07882;-2.66070;,
 -0.77127;0.03801;-3.58115;,
 -0.01161;0.03789;-3.60597;,
 -0.00434;1.48011;-2.86904;,
 -0.19823;0.63842;-4.10135;,
 0.07339;2.07395;-2.17130;,
 0.13519;2.83264;-1.56321;,
 0.16887;3.90790;-1.04242;,
 0.09030;3.80910;-0.62894;,
 0.09030;3.78878;-0.39554;,
 0.80559;0.27885;-3.85096;,
 0.44753;0.27880;-3.83842;,
 2.00717;0.27906;-3.69267;,
 2.23417;0.14167;-2.70828;,
 2.38048;0.00425;-2.03297;,
 2.47280;-0.24660;-0.47282;,
 0.82393;-0.24617;-0.47533;,
 0.33979;-0.24604;-0.47608;,
 -1.59949;-0.24597;-0.47657;,
 -0.38641;-0.24585;-0.47721;,
 -1.30685;0.00410;-1.86641;,
 -1.16735;0.14107;-2.70448;,
 -0.08957;0.27872;-3.81962;,
 -0.98261;0.27880;-3.78998;;
 
 184;
 4;0,1,2,3;,
 4;2,1,4,5;,
 4;6,7,1,0;,
 4;1,7,8,4;,
 4;9,10,11,12;,
 4;11,10,13,14;,
 4;15,16,17,18;,
 4;17,16,19,20;,
 4;21,22,16,15;,
 4;16,22,23,19;,
 4;24,25,14,13;,
 4;26,25,24,27;,
 4;28,29,30,31;,
 4;31,30,32,33;,
 4;3,2,34,35;,
 4;34,2,5,36;,
 4;37,38,26,27;,
 4;22,39,40,23;,
 4;41,39,22,21;,
 4;32,42,43,33;,
 4;30,44,45,32;,
 4;26,46,47,25;,
 4;11,48,49,12;,
 4;29,50,44,30;,
 4;25,47,51,14;,
 4;14,51,48,11;,
 4;32,45,52,42;,
 4;38,53,46,26;,
 4;44,54,55,45;,
 4;46,56,57,47;,
 4;48,58,59,49;,
 4;50,60,54,44;,
 4;47,57,61,51;,
 4;51,61,58,48;,
 4;45,55,62,52;,
 4;53,63,56,46;,
 4;54,64,65,55;,
 4;56,5,4,57;,
 4;58,7,6,59;,
 4;60,66,64,54;,
 4;57,4,8,61;,
 4;61,8,7,58;,
 4;55,65,67,62;,
 4;63,36,5,56;,
 4;68,69,70,71;,
 4;72,68,71,73;,
 4;74,72,73,75;,
 4;29,28,76,77;,
 4;78,50,29,77;,
 4;79,60,50,78;,
 4;80,66,60,79;,
 4;64,66,80,81;,
 4;65,64,81,82;,
 4;67,65,82,83;,
 4;84,85,10,9;,
 4;10,85,86,13;,
 4;13,86,87,24;,
 4;24,87,88,27;,
 4;27,88,89,37;,
 4;37,89,90,91;,
 4;91,90,92,93;,
 4;94,95,96,43;,
 4;43,96,97,33;,
 4;33,97,98,31;,
 4;28,99,100,76;,
 4;31,98,99,28;,
 4;18,17,85,84;,
 4;85,17,20,86;,
 4;86,20,19,87;,
 4;87,19,23,88;,
 4;88,23,40,89;,
 4;89,40,39,90;,
 4;90,39,41,92;,
 4;95,70,69,96;,
 4;96,69,68,97;,
 4;97,68,72,98;,
 4;99,74,75,100;,
 4;98,72,74,99;,
 4;101,102,103,104;,
 4;102,105,106,103;,
 4;104,103,107,108;,
 4;103,106,109,107;,
 4;110,111,112,113;,
 4;111,114,115,112;,
 4;116,117,118,119;,
 4;117,120,121,118;,
 4;119,118,122,123;,
 4;118,121,124,122;,
 4;125,115,114,126;,
 4;127,128,125,126;,
 4;129,130,131,132;,
 4;130,133,134,131;,
 4;35,34,102,101;,
 4;34,36,105,102;,
 4;37,128,127,38;,
 4;122,124,135,136;,
 4;123,122,136,137;,
 4;134,133,43,42;,
 4;131,134,138,139;,
 4;127,126,140,141;,
 4;111,110,142,143;,
 4;132,131,139,144;,
 4;126,114,145,140;,
 4;114,111,143,145;,
 4;134,42,52,138;,
 4;38,127,141,53;,
 4;139,138,146,147;,
 4;141,140,148,149;,
 4;143,142,150,151;,
 4;144,139,147,152;,
 4;140,145,153,148;,
 4;145,143,151,153;,
 4;138,52,62,146;,
 4;53,141,149,63;,
 4;147,146,154,155;,
 4;149,148,106,105;,
 4;151,150,108,107;,
 4;152,147,155,156;,
 4;148,153,109,106;,
 4;153,151,107,109;,
 4;146,62,67,154;,
 4;63,149,105,36;,
 4;157,158,159,160;,
 4;161,162,158,157;,
 4;163,164,162,161;,
 4;132,165,166,129;,
 4;167,165,132,144;,
 4;168,167,144,152;,
 4;169,168,152,156;,
 4;155,170,169,156;,
 4;154,171,170,155;,
 4;67,83,171,154;,
 4;113,112,172,173;,
 4;112,115,174,172;,
 4;115,125,175,174;,
 4;125,128,176,175;,
 4;128,37,177,176;,
 4;37,91,178,177;,
 4;91,93,179,178;,
 4;94,43,180,181;,
 4;43,133,182,180;,
 4;133,130,183,182;,
 4;129,166,184,185;,
 4;130,129,185,183;,
 4;173,172,117,116;,
 4;172,174,120,117;,
 4;174,175,121,120;,
 4;175,176,124,121;,
 4;176,177,135,124;,
 4;177,178,136,135;,
 4;178,179,137,136;,
 4;181,180,160,159;,
 4;180,182,157,160;,
 4;182,183,161,157;,
 4;185,184,164,163;,
 4;183,185,163,161;,
 4;92,95,94,93;,
 4;41,70,95,92;,
 4;70,41,21,71;,
 4;71,21,15,73;,
 4;73,15,18,75;,
 4;100,75,18,84;,
 4;76,100,84,9;,
 4;76,9,12,77;,
 4;49,78,77,12;,
 4;59,79,78,49;,
 4;6,80,79,59;,
 4;80,6,0,81;,
 4;81,0,3,82;,
 4;82,3,35,83;,
 4;171,83,35,101;,
 4;170,171,101,104;,
 4;169,170,104,108;,
 4;150,168,169,108;,
 4;142,167,168,150;,
 4;110,165,167,142;,
 4;166,165,110,113;,
 4;166,113,173,184;,
 4;184,173,116,164;,
 4;162,164,116,119;,
 4;158,162,119,123;,
 4;159,158,123,137;,
 4;179,181,159,137;,
 4;93,94,181,179;;
 
 MeshMaterialList {
  5;
  184;
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
   TextureFilename {
    "data\\TEXTURE\\enemy\\Samurai_UV.jpg";
   }
  }
  Material {
   0.401569;0.401569;0.401569;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.398431;0.401569;0.323137;1.000000;;
   5.000000;
   0.320000;0.320000;0.320000;;
   0.049804;0.050196;0.040392;;
  }
  Material {
   0.424471;0.424471;0.424471;1.000000;;
   5.000000;
   1.000000;1.000000;1.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.410000;0.410000;0.410000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  238;
  -0.926451;0.376416;0.000000;,
  -0.000548;-1.000000;-0.000000;,
  0.932421;0.361373;0.000000;,
  -0.912903;0.408177;0.000000;,
  0.929626;0.368505;0.000000;,
  -0.930043;0.354760;0.095734;,
  0.908319;0.406335;0.099241;,
  -0.896475;0.410354;0.167158;,
  0.035491;0.791328;0.610361;,
  0.564972;0.700365;0.436228;,
  -0.883113;0.449709;0.133689;,
  0.029212;0.816126;0.577135;,
  0.528290;0.748750;0.400353;,
  -0.908632;0.407722;0.090281;,
  0.867482;0.487799;0.097610;,
  -0.926011;0.347856;0.146627;,
  0.925551;0.357552;0.124551;,
  0.909412;0.405943;0.090447;,
  -0.920192;0.366856;0.136617;,
  -0.933475;0.333139;0.132826;,
  -0.937975;0.328233;0.111650;,
  0.938126;0.284234;0.197814;,
  0.944268;0.309964;0.110817;,
  0.035438;0.694883;0.718249;,
  -0.895113;0.387021;0.221329;,
  0.614229;0.595333;0.517978;,
  -0.912467;0.409151;0.000000;,
  0.946224;0.323511;-0.000000;,
  -0.966717;0.251975;0.044347;,
  -0.939384;0.302353;0.161680;,
  0.956880;0.224900;0.183851;,
  0.958856;0.242974;0.146827;,
  0.015985;0.550962;0.834377;,
  -0.559040;0.512296;0.651942;,
  0.931908;0.277272;0.233810;,
  -0.961649;0.274282;0.000000;,
  0.967758;0.251882;-0.000000;,
  -0.986283;0.163775;-0.020564;,
  -0.035206;0.989041;-0.143384;,
  -0.055393;0.977561;-0.203239;,
  -0.948104;0.246248;0.201149;,
  -0.091310;0.984635;-0.148850;,
  -0.109482;0.968937;-0.221753;,
  -0.067621;0.946005;-0.317021;,
  -0.553340;0.431613;0.712408;,
  -0.124249;0.927397;-0.352842;,
  -0.985551;0.169382;0.000000;,
  -0.028463;0.999595;0.000000;,
  -0.091697;0.995787;0.000000;,
  -0.000178;-1.000000;0.000000;,
  -0.042500;0.829346;0.557117;,
  -0.059720;0.797759;0.600011;,
  -0.085382;0.698604;0.710396;,
  -0.098222;0.545196;0.832534;,
  -0.102207;0.457536;0.883298;,
  0.027832;0.973309;-0.227805;,
  -0.000893;0.989888;-0.141851;,
  -0.006244;0.999981;0.000000;,
  -0.026029;-0.644644;0.764040;,
  0.036180;-0.651471;0.757811;,
  0.379331;-0.756321;0.532998;,
  0.603262;-0.752544;0.264107;,
  0.596979;-0.770804;0.222435;,
  0.329899;-0.927523;-0.175691;,
  -0.000873;-0.879177;-0.476494;,
  -0.000286;-0.880111;-0.474768;,
  -0.656192;-0.713414;0.245871;,
  -0.240846;-0.935594;-0.258182;,
  -0.656258;-0.723151;0.215355;,
  -0.377753;-0.755981;0.534598;,
  -0.000232;-0.990114;0.140263;,
  -0.014653;-0.886314;0.462853;,
  0.020157;-0.888263;0.458893;,
  -0.001298;-0.989549;0.144189;,
  0.251273;-0.882382;0.397824;,
  0.307580;-0.926190;0.218100;,
  0.001749;-0.985703;0.168481;,
  -0.004943;-0.985425;0.170037;,
  0.298574;-0.931546;0.207546;,
  0.207146;-0.976908;-0.052359;,
  -0.002927;-0.987375;-0.158371;,
  0.000775;-0.987779;-0.155860;,
  -0.339292;-0.914372;0.220917;,
  -0.239209;-0.970899;-0.011575;,
  -0.340801;-0.920730;0.190029;,
  -0.246615;-0.884860;0.395226;,
  -0.930043;0.354760;-0.095734;,
  0.908319;0.406335;-0.099241;,
  -0.896475;0.410354;-0.167158;,
  0.035491;0.791328;-0.610361;,
  0.564972;0.700366;-0.436228;,
  -0.883113;0.449709;-0.133689;,
  0.029213;0.816127;-0.577134;,
  0.528290;0.748751;-0.400353;,
  -0.908632;0.407722;-0.090281;,
  0.867482;0.487798;-0.097610;,
  -0.926011;0.347856;-0.146627;,
  0.925551;0.357552;-0.124551;,
  0.909412;0.405943;-0.090447;,
  -0.920192;0.366856;-0.136617;,
  -0.933475;0.333139;-0.132826;,
  -0.937975;0.328233;-0.111649;,
  0.938126;0.284234;-0.197814;,
  0.944268;0.309964;-0.110817;,
  0.035438;0.694883;-0.718249;,
  -0.895113;0.387021;-0.221329;,
  0.614229;0.595333;-0.517978;,
  -0.966717;0.251975;-0.044347;,
  -0.939384;0.302353;-0.161680;,
  0.956880;0.224900;-0.183851;,
  0.958856;0.242974;-0.146827;,
  0.015985;0.550962;-0.834377;,
  -0.559040;0.512296;-0.651942;,
  0.931908;0.277272;-0.233810;,
  -0.986283;0.163775;0.020565;,
  -0.035206;0.989041;0.143384;,
  -0.055393;0.977561;0.203239;,
  -0.948104;0.246248;-0.201149;,
  -0.091310;0.984635;0.148850;,
  -0.109482;0.968937;0.221753;,
  -0.067621;0.946005;0.317021;,
  -0.553340;0.431613;-0.712408;,
  -0.124249;0.927397;0.352842;,
  -0.042500;0.829346;-0.557116;,
  -0.059720;0.797760;-0.600011;,
  -0.085382;0.698604;-0.710396;,
  -0.098222;0.545196;-0.832534;,
  -0.102207;0.457536;-0.883298;,
  0.027832;0.973309;0.227805;,
  -0.000893;0.989888;0.141851;,
  -0.026029;-0.644645;-0.764039;,
  0.036179;-0.651471;-0.757811;,
  0.379331;-0.756321;-0.532998;,
  0.603262;-0.752544;-0.264107;,
  0.596979;-0.770804;-0.222435;,
  0.329899;-0.927523;0.175691;,
  -0.000872;-0.879177;0.476494;,
  -0.000286;-0.880111;0.474768;,
  -0.656192;-0.713414;-0.245871;,
  -0.240846;-0.935594;0.258182;,
  -0.656255;-0.723154;-0.215354;,
  -0.377749;-0.755984;-0.534596;,
  -0.000232;-0.990114;-0.140263;,
  -0.014653;-0.886314;-0.462853;,
  0.020157;-0.888263;-0.458893;,
  -0.001298;-0.989549;-0.144189;,
  0.251274;-0.882382;-0.397823;,
  0.307580;-0.926190;-0.218100;,
  0.001749;-0.985703;-0.168481;,
  -0.004943;-0.985425;-0.170037;,
  0.298574;-0.931546;-0.207546;,
  0.207146;-0.976908;0.052359;,
  -0.002927;-0.987375;0.158371;,
  0.000775;-0.987779;0.155860;,
  -0.339292;-0.914372;-0.220917;,
  -0.239209;-0.970899;0.011575;,
  -0.340808;-0.920727;-0.190030;,
  -0.246624;-0.884857;-0.395228;,
  -0.000548;-1.000000;0.000000;,
  -0.000877;-0.879872;-0.475210;,
  0.000338;-0.987901;-0.155085;,
  0.001766;-0.985756;0.168171;,
  -0.000181;-0.990445;0.137905;,
  -0.015028;-0.886823;0.461865;,
  -0.026587;-0.644545;0.764104;,
  -0.043675;0.817526;0.574233;,
  -0.060368;0.790837;0.609042;,
  -0.085411;0.698340;0.710652;,
  -0.074079;0.549762;0.832030;,
  -0.010640;0.964262;-0.264735;,
  -0.001360;0.984302;-0.176489;,
  0.021102;0.992038;-0.124160;,
  0.034699;0.999398;0.000000;,
  0.021102;0.992038;0.124160;,
  -0.001360;0.984302;0.176489;,
  -0.010640;0.964262;0.264735;,
  -0.074079;0.549762;-0.832030;,
  -0.085411;0.698340;-0.710652;,
  -0.060368;0.790838;-0.609041;,
  -0.043675;0.817527;-0.574232;,
  -0.026588;-0.644545;-0.764104;,
  -0.015029;-0.886823;-0.461865;,
  -0.000181;-0.990445;-0.137905;,
  0.001766;-0.985756;-0.168171;,
  0.000338;-0.987901;0.155085;,
  -0.000877;-0.879872;0.475210;,
  0.105763;0.541016;0.834336;,
  0.973305;0.188543;0.130881;,
  0.967478;0.185749;0.171710;,
  0.003176;0.481276;0.876563;,
  -0.054270;0.465882;0.883181;,
  0.931972;0.224789;0.284427;,
  0.060576;0.481435;0.874386;,
  0.971561;0.236789;-0.000000;,
  -0.059332;0.801867;0.594549;,
  -0.041795;0.836260;0.546737;,
  -0.085364;0.698773;0.710232;,
  0.056921;0.956591;-0.285822;,
  0.112436;0.926160;-0.359981;,
  0.051098;0.950668;-0.305974;,
  -0.023019;0.984712;-0.172664;,
  -0.047297;0.998881;0.000000;,
  0.037495;-0.627835;0.777443;,
  -0.026998;-0.620778;0.783522;,
  0.392075;-0.739265;0.547507;,
  0.620770;-0.737482;0.266016;,
  0.614332;-0.757026;0.222504;,
  0.346131;-0.938186;0.000000;,
  -0.264923;-0.958660;-0.103855;,
  -0.676372;-0.687230;0.265020;,
  -0.673750;-0.696861;0.245856;,
  -0.672819;-0.707677;0.215656;,
  -0.389685;-0.739231;0.549257;,
  -0.026668;-0.620956;0.783392;,
  0.105763;0.541016;-0.834336;,
  0.967478;0.185749;-0.171710;,
  0.973305;0.188543;-0.130881;,
  -0.054270;0.465882;-0.883181;,
  0.003176;0.481276;-0.876563;,
  0.931972;0.224789;-0.284427;,
  0.060576;0.481435;-0.874386;,
  -0.059332;0.801867;-0.594549;,
  -0.041795;0.836261;-0.546736;,
  -0.085364;0.698773;-0.710232;,
  0.056921;0.956591;0.285822;,
  0.051098;0.950668;0.305974;,
  0.112436;0.926160;0.359981;,
  -0.023019;0.984712;0.172664;,
  -0.026998;-0.620778;-0.783521;,
  0.037495;-0.627835;-0.777443;,
  0.392076;-0.739265;-0.547507;,
  0.620770;-0.737482;-0.266016;,
  0.614332;-0.757026;-0.222504;,
  -0.673750;-0.696861;-0.245856;,
  -0.676372;-0.687230;-0.265020;,
  -0.672801;-0.707694;-0.215655;,
  -0.389664;-0.739246;-0.549252;,
  -0.026668;-0.620956;-0.783391;;
  184;
  4;170,39,38,171;,
  4;38,39,42,41;,
  4;169,43,39,170;,
  4;39,43,45,42;,
  4;165,11,8,166;,
  4;8,11,12,9;,
  4;162,73,72,163;,
  4;72,73,75,74;,
  4;161,77,73,162;,
  4;73,77,78,75;,
  4;14,6,9,12;,
  4;16,6,14,17;,
  4;10,7,5,13;,
  4;13,5,15,18;,
  4;171,38,47,172;,
  4;47,38,41,48;,
  4;2,4,16,17;,
  4;77,80,79,78;,
  4;160,80,77,161;,
  4;15,3,0,18;,
  4;5,20,19,15;,
  4;16,21,22,6;,
  4;8,23,167,166;,
  4;7,24,20,5;,
  4;6,22,25,9;,
  4;9,25,23,8;,
  4;15,19,26,3;,
  4;4,27,21,16;,
  4;20,29,28,19;,
  4;21,30,31,22;,
  4;23,32,168,167;,
  4;24,33,29,20;,
  4;22,31,34,25;,
  4;25,186,32,23;,
  4;19,28,35,26;,
  4;27,36,30,21;,
  4;29,40,37,28;,
  4;30,187,188,31;,
  4;32,189,190,168;,
  4;33,44,40,29;,
  4;31,188,191,34;,
  4;186,192,189,32;,
  4;28,37,46,35;,
  4;36,193,187,30;,
  4;82,83,81,76;,
  4;84,82,76,70;,
  4;85,84,70,71;,
  4;194,195,50,51;,
  4;52,196,194,51;,
  4;53,33,196,52;,
  4;54,44,33,53;,
  4;197,198,199,55;,
  4;200,197,55,56;,
  4;201,200,56,57;,
  4;164,59,202,203;,
  4;202,59,60,204;,
  4;204,60,61,205;,
  4;205,61,62,206;,
  4;206,62,63,207;,
  4;207,63,64,1;,
  4;1,64,159,158;,
  4;49,65,67,208;,
  4;209,209,66,210;,
  4;210,66,68,211;,
  4;212,69,58,213;,
  4;211,68,69,212;,
  4;163,72,59,164;,
  4;59,72,74,60;,
  4;60,74,75,61;,
  4;61,75,78,62;,
  4;62,78,79,63;,
  4;63,79,80,64;,
  4;64,80,160,159;,
  4;65,81,83,67;,
  4;67,83,82,66;,
  4;66,82,84,68;,
  4;69,85,71,58;,
  4;68,84,85,69;,
  4;173,115,116,174;,
  4;115,118,119,116;,
  4;174,116,120,175;,
  4;116,119,122,120;,
  4;178,89,92,179;,
  4;89,90,93,92;,
  4;181,144,145,182;,
  4;144,146,147,145;,
  4;182,145,149,183;,
  4;145,147,150,149;,
  4;95,93,90,87;,
  4;97,98,95,87;,
  4;91,94,86,88;,
  4;94,99,96,86;,
  4;172,47,115,173;,
  4;47,48,118,115;,
  4;2,98,97,4;,
  4;149,150,151,152;,
  4;183,149,152,184;,
  4;96,99,0,3;,
  4;86,96,100,101;,
  4;97,87,103,102;,
  4;89,178,177,104;,
  4;88,86,101,105;,
  4;87,90,106,103;,
  4;90,89,104,106;,
  4;96,3,26,100;,
  4;4,97,102,27;,
  4;101,100,107,108;,
  4;102,103,110,109;,
  4;104,177,176,111;,
  4;105,101,108,112;,
  4;103,106,113,110;,
  4;106,104,111,214;,
  4;100,26,35,107;,
  4;27,102,109,36;,
  4;108,107,114,117;,
  4;109,110,215,216;,
  4;111,176,217,218;,
  4;112,108,117,121;,
  4;110,113,219,215;,
  4;214,111,218,220;,
  4;107,35,46,114;,
  4;36,109,216,193;,
  4;154,148,153,155;,
  4;156,142,148,154;,
  4;157,143,142,156;,
  4;221,124,123,222;,
  4;125,124,221,223;,
  4;126,125,223,112;,
  4;127,126,112,121;,
  4;224,128,225,226;,
  4;227,129,128,224;,
  4;201,57,129,227;,
  4;228,229,131,180;,
  4;229,230,132,131;,
  4;230,231,133,132;,
  4;231,232,134,133;,
  4;232,207,135,134;,
  4;207,1,136,135;,
  4;1,158,185,136;,
  4;49,208,139,137;,
  4;208,233,138,234;,
  4;233,235,140,138;,
  4;236,237,130,141;,
  4;235,236,141,140;,
  4;180,131,144,181;,
  4;131,132,146,144;,
  4;132,133,147,146;,
  4;133,134,150,147;,
  4;134,135,151,150;,
  4;135,136,152,151;,
  4;136,185,184,152;,
  4;137,139,155,153;,
  4;139,138,154,155;,
  4;138,140,156,154;,
  4;141,130,143,157;,
  4;140,141,157,156;,
  4;159,65,49,158;,
  4;160,81,65,159;,
  4;81,160,161,76;,
  4;76,161,162,70;,
  4;70,162,163,71;,
  4;58,71,163,164;,
  4;213,58,164,203;,
  4;50,165,166,51;,
  4;167,52,51,166;,
  4;168,53,52,167;,
  4;190,54,53,168;,
  4;199,169,170,55;,
  4;55,170,171,56;,
  4;56,171,172,57;,
  4;129,57,172,173;,
  4;128,129,173,174;,
  4;225,128,174,175;,
  4;176,126,127,217;,
  4;177,125,126,176;,
  4;178,124,125,177;,
  4;123,124,178,179;,
  4;237,228,180,130;,
  4;130,180,181,143;,
  4;142,143,181,182;,
  4;148,142,182,183;,
  4;153,148,183,184;,
  4;185,137,153,184;,
  4;158,49,137,185;;
 }
 MeshTextureCoords {
  186;
  0.421460;0.715550;,
  0.421460;0.715690;,
  0.414470;0.716820;,
  0.414470;0.716680;,
  0.421460;0.711300;,
  0.414470;0.712440;,
  0.433740;0.709210;,
  0.433660;0.708780;,
  0.431460;0.703730;,
  0.526170;0.892090;,
  0.526610;0.892090;,
  0.492040;0.845180;,
  0.490660;0.845180;,
  0.520810;0.892090;,
  0.485130;0.845180;,
  0.482390;0.932060;,
  0.482420;0.932050;,
  0.511480;0.925560;,
  0.511150;0.925560;,
  0.482530;0.932020;,
  0.507470;0.925540;,
  0.460310;0.938500;,
  0.460090;0.938500;,
  0.465450;0.938490;,
  0.484830;0.901440;,
  0.450220;0.845180;,
  0.428020;0.845180;,
  0.460070;0.910790;,
  0.524410;0.892090;,
  0.485130;0.845180;,
  0.450220;0.845180;,
  0.484830;0.901440;,
  0.428020;0.845180;,
  0.454070;0.910790;,
  0.403280;0.721260;,
  0.403280;0.720210;,
  0.403280;0.716870;,
  0.403280;0.927680;,
  0.403280;0.845180;,
  0.425780;0.950360;,
  0.425680;0.950390;,
  0.425810;0.950350;,
  0.403280;0.845180;,
  0.403280;0.927680;,
  0.438630;0.812070;,
  0.416430;0.812070;,
  0.416430;0.812070;,
  0.438630;0.812070;,
  0.471130;0.812070;,
  0.469750;0.812070;,
  0.464220;0.812070;,
  0.464220;0.812070;,
  0.403280;0.800030;,
  0.403280;0.800030;,
  0.428940;0.769780;,
  0.410730;0.769780;,
  0.410730;0.769780;,
  0.428940;0.769780;,
  0.452290;0.769780;,
  0.451150;0.769780;,
  0.446620;0.769780;,
  0.449930;0.769780;,
  0.403280;0.757740;,
  0.403280;0.757740;,
  0.419820;0.714310;,
  0.414470;0.717770;,
  0.428880;0.706560;,
  0.403280;0.721400;,
  0.461190;0.938500;,
  0.425830;0.950340;,
  0.425860;0.950330;,
  0.460630;0.938510;,
  0.482370;0.932060;,
  0.482340;0.932080;,
  0.509920;0.925560;,
  0.510660;0.925570;,
  0.525510;0.892090;,
  0.488580;0.845180;,
  0.467680;0.812070;,
  0.449450;0.769780;,
  0.433850;0.709840;,
  0.421460;0.715350;,
  0.414470;0.716480;,
  0.403280;0.718620;,
  0.517630;0.912140;,
  0.518010;0.912140;,
  0.513260;0.912130;,
  0.483770;0.919790;,
  0.463530;0.927440;,
  0.416780;0.941430;,
  0.416860;0.941400;,
  0.403280;0.927680;,
  0.416880;0.941400;,
  0.403280;0.927680;,
  0.403280;0.927680;,
  0.416910;0.941390;,
  0.416890;0.941390;,
  0.458540;0.927450;,
  0.483650;0.919820;,
  0.516180;0.912140;,
  0.517070;0.912150;,
  0.392090;0.716680;,
  0.392090;0.716820;,
  0.385100;0.715690;,
  0.385100;0.715550;,
  0.392090;0.712440;,
  0.385100;0.711300;,
  0.372900;0.708780;,
  0.372820;0.709210;,
  0.375100;0.703730;,
  0.315900;0.845180;,
  0.314520;0.845180;,
  0.279950;0.892090;,
  0.280390;0.892090;,
  0.321430;0.845180;,
  0.285740;0.892090;,
  0.295410;0.925560;,
  0.295080;0.925560;,
  0.324140;0.932050;,
  0.324170;0.932060;,
  0.299090;0.925540;,
  0.324030;0.932020;,
  0.346470;0.938500;,
  0.346250;0.938500;,
  0.341100;0.938490;,
  0.321730;0.901440;,
  0.356340;0.845180;,
  0.378540;0.845180;,
  0.346490;0.910790;,
  0.282150;0.892090;,
  0.321730;0.901440;,
  0.356340;0.845180;,
  0.321430;0.845180;,
  0.352490;0.910790;,
  0.378540;0.845180;,
  0.380880;0.950390;,
  0.380780;0.950360;,
  0.380740;0.950350;,
  0.390130;0.812070;,
  0.367930;0.812070;,
  0.367930;0.812070;,
  0.390130;0.812070;,
  0.336810;0.812070;,
  0.335430;0.812070;,
  0.342340;0.812070;,
  0.342340;0.812070;,
  0.395830;0.769780;,
  0.377620;0.769780;,
  0.377620;0.769780;,
  0.395830;0.769780;,
  0.355400;0.769780;,
  0.354270;0.769780;,
  0.359940;0.769780;,
  0.356630;0.769780;,
  0.392090;0.717770;,
  0.386740;0.714310;,
  0.377680;0.706560;,
  0.345360;0.938500;,
  0.345930;0.938510;,
  0.380700;0.950330;,
  0.380720;0.950340;,
  0.324190;0.932060;,
  0.324220;0.932080;,
  0.296640;0.925560;,
  0.295890;0.925570;,
  0.317980;0.845180;,
  0.281050;0.892090;,
  0.338880;0.812070;,
  0.357100;0.769780;,
  0.372710;0.709840;,
  0.385100;0.715350;,
  0.392090;0.716480;,
  0.288550;0.912140;,
  0.288930;0.912140;,
  0.293300;0.912130;,
  0.322790;0.919790;,
  0.343030;0.927440;,
  0.389780;0.941430;,
  0.389700;0.941400;,
  0.389680;0.941400;,
  0.389670;0.941390;,
  0.389650;0.941390;,
  0.348020;0.927450;,
  0.322910;0.919820;,
  0.289490;0.912150;,
  0.290380;0.912140;;
 }
}
