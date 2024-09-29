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
 448;
 -44.00043;11.30000;26.99962;,
 44.00300;11.30000;27.00000;,
 44.00000;11.30000;-27.00000;,
 -44.00000;11.30000;-27.00000;,
 -43.99999;8.00000;-27.00000;,
 44.00000;8.00000;-27.00000;,
 44.00300;8.00000;27.00000;,
 -43.99699;8.00000;27.00000;,
 -44.00000;9.65000;-27.00000;,
 -44.00000;11.30000;-27.00000;,
 44.00000;11.30000;-27.00000;,
 44.00000;9.65000;-27.00000;,
 44.00000;8.00000;-27.00000;,
 -43.99999;8.00000;-27.00000;,
 -44.00000;9.65000;-27.00000;,
 -43.99999;8.00000;-27.00000;,
 -43.99700;9.65000;27.00000;,
 -44.00000;11.30000;-27.00000;,
 44.00000;9.65000;-27.00000;,
 44.00000;11.30000;-27.00000;,
 44.00300;9.65000;27.00000;,
 44.00000;8.00000;-27.00000;,
 -43.99700;9.65000;27.00000;,
 -43.99699;8.00000;27.00000;,
 44.00300;8.00000;27.00000;,
 44.00300;9.65000;27.00000;,
 44.00300;11.30000;27.00000;,
 -44.00043;11.30000;26.99962;,
 -37.95000;8.00000;-24.75000;,
 -29.70000;8.00000;-24.75000;,
 -29.70010;-0.25000;-24.75000;,
 -37.95010;-0.25000;-24.75000;,
 -29.70000;8.00000;-24.75000;,
 -29.70000;8.00000;-19.80000;,
 -29.70010;-0.25000;-19.80000;,
 -29.70010;-0.25000;-24.75000;,
 -29.70000;8.00000;-19.80000;,
 -37.95000;8.00000;-19.80000;,
 -37.95010;-0.25000;-19.80000;,
 -29.70010;-0.25000;-19.80000;,
 -37.95000;8.00000;-19.80000;,
 -37.95000;8.00000;-24.75000;,
 -37.95010;-0.25000;-24.75000;,
 -37.95010;-0.25000;-19.80000;,
 -29.70000;8.00000;-24.75000;,
 -37.95000;8.00000;-24.75000;,
 -37.95010;-0.25000;-24.75000;,
 -29.70010;-0.25000;-24.75000;,
 -37.95000;8.00000;19.80000;,
 -29.70000;8.00000;19.80000;,
 -29.70010;-0.25000;19.80000;,
 -37.95010;-0.25000;19.80000;,
 -29.70000;8.00000;19.80000;,
 -29.70000;8.00000;24.75000;,
 -29.70010;-0.25000;24.75000;,
 -29.70010;-0.25000;19.80000;,
 -29.70000;8.00000;24.75000;,
 -37.95000;8.00000;24.75000;,
 -37.95010;-0.25000;24.75000;,
 -29.70010;-0.25000;24.75000;,
 -37.95000;8.00000;24.75000;,
 -37.95000;8.00000;19.80000;,
 -37.95010;-0.25000;19.80000;,
 -37.95010;-0.25000;24.75000;,
 -29.70000;8.00000;19.80000;,
 -37.95000;8.00000;19.80000;,
 -37.95010;-0.25000;19.80000;,
 -29.70010;-0.25000;19.80000;,
 29.70000;8.00000;19.80000;,
 37.95000;8.00000;19.80000;,
 37.94990;-0.25000;19.80000;,
 29.69990;-0.25000;19.80000;,
 37.95000;8.00000;19.80000;,
 37.95000;8.00000;24.75000;,
 37.94990;-0.25000;24.75000;,
 37.94990;-0.25000;19.80000;,
 37.95000;8.00000;24.75000;,
 29.70000;8.00000;24.75000;,
 29.69990;-0.25000;24.75000;,
 37.94990;-0.25000;24.75000;,
 29.70000;8.00000;24.75000;,
 29.70000;8.00000;19.80000;,
 29.69990;-0.25000;19.80000;,
 29.69990;-0.25000;24.75000;,
 37.95000;8.00000;19.80000;,
 29.70000;8.00000;19.80000;,
 29.69990;-0.25000;19.80000;,
 37.94990;-0.25000;19.80000;,
 29.70000;8.00000;-24.75000;,
 37.95000;8.00000;-24.75000;,
 37.94990;-0.25000;-24.75000;,
 29.69990;-0.25000;-24.75000;,
 37.95000;8.00000;-24.75000;,
 37.95000;8.00000;-19.80000;,
 37.94990;-0.25000;-19.80000;,
 37.94990;-0.25000;-24.75000;,
 37.95000;8.00000;-19.80000;,
 29.70000;8.00000;-19.80000;,
 29.69990;-0.25000;-19.80000;,
 37.94990;-0.25000;-19.80000;,
 29.70000;8.00000;-19.80000;,
 29.70000;8.00000;-24.75000;,
 29.69990;-0.25000;-24.75000;,
 29.69990;-0.25000;-19.80000;,
 37.95000;8.00000;-24.75000;,
 29.70000;8.00000;-24.75000;,
 29.69990;-0.25000;-24.75000;,
 37.94990;-0.25000;-24.75000;,
 40.00000;40.00000;-27.00000;,
 44.00031;39.99988;-27.00017;,
 44.00031;11.29988;-27.00017;,
 40.00000;11.30000;-27.00000;,
 44.00031;39.99988;-27.00017;,
 44.00000;40.00000;-23.00000;,
 44.00000;11.30000;-23.00000;,
 44.00031;11.29988;-27.00017;,
 44.00000;40.00000;-23.00000;,
 39.99969;40.00012;-22.99983;,
 39.99969;11.30012;-22.99983;,
 44.00000;11.30000;-23.00000;,
 39.99969;40.00012;-22.99983;,
 40.00000;40.00000;-27.00000;,
 40.00000;11.30000;-27.00000;,
 39.99969;11.30012;-22.99983;,
 44.00031;39.99988;-27.00017;,
 40.00000;40.00000;-27.00000;,
 40.00000;11.30000;-27.00000;,
 44.00031;11.29988;-27.00017;,
 40.00000;40.00000;23.00000;,
 44.00031;39.99988;22.99983;,
 44.00031;11.29988;22.99983;,
 40.00000;11.30000;23.00000;,
 44.00031;39.99988;22.99983;,
 44.00000;40.00000;27.00000;,
 44.00000;11.30000;27.00000;,
 44.00031;11.29988;22.99983;,
 44.00000;40.00000;27.00000;,
 39.99969;40.00012;27.00017;,
 39.99969;11.30012;27.00017;,
 44.00000;11.30000;27.00000;,
 39.99969;40.00012;27.00017;,
 40.00000;40.00000;23.00000;,
 40.00000;11.30000;23.00000;,
 39.99969;11.30012;27.00017;,
 44.00031;39.99988;22.99983;,
 40.00000;40.00000;23.00000;,
 40.00000;11.30000;23.00000;,
 44.00031;11.29988;22.99983;,
 -44.00000;40.00000;-27.00000;,
 -39.99969;39.99988;-27.00017;,
 -39.99969;11.29988;-27.00017;,
 -44.00000;11.30000;-27.00000;,
 -39.99969;39.99988;-27.00017;,
 -40.00000;40.00000;-23.00000;,
 -40.00000;11.30000;-23.00000;,
 -39.99969;11.29988;-27.00017;,
 -40.00000;40.00000;-23.00000;,
 -44.00031;40.00012;-22.99983;,
 -44.00031;11.30012;-22.99983;,
 -40.00000;11.30000;-23.00000;,
 -44.00031;40.00012;-22.99983;,
 -44.00000;40.00000;-27.00000;,
 -44.00000;11.30000;-27.00000;,
 -44.00031;11.30012;-22.99983;,
 -39.99969;39.99988;-27.00017;,
 -44.00000;40.00000;-27.00000;,
 -44.00000;11.30000;-27.00000;,
 -39.99969;11.29988;-27.00017;,
 -44.00000;40.00000;23.00000;,
 -39.99969;39.99988;22.99983;,
 -39.99969;11.29988;22.99983;,
 -44.00000;11.30000;23.00000;,
 -39.99969;39.99988;22.99983;,
 -40.00000;40.00000;27.00000;,
 -40.00000;11.30000;27.00000;,
 -39.99969;11.29988;22.99983;,
 -40.00000;40.00000;27.00000;,
 -44.00031;40.00012;27.00017;,
 -44.00031;11.30012;27.00017;,
 -40.00000;11.30000;27.00000;,
 -44.00031;40.00012;27.00017;,
 -44.00000;40.00000;23.00000;,
 -44.00000;11.30000;23.00000;,
 -44.00031;11.30012;27.00017;,
 -39.99969;39.99988;22.99983;,
 -44.00000;40.00000;23.00000;,
 -44.00000;11.30000;23.00000;,
 -39.99969;11.29988;22.99983;,
 -40.00000;13.00000;-27.00000;,
 40.00000;13.00000;-27.00000;,
 40.00000;11.30000;-27.00000;,
 -40.00000;11.30000;-27.00000;,
 40.00000;13.00000;-27.00000;,
 39.99969;13.00012;-22.99983;,
 39.99969;11.30012;-22.99983;,
 40.00000;11.30000;-27.00000;,
 39.99969;13.00012;-22.99983;,
 -40.00031;13.00012;-22.99983;,
 -40.00031;11.30012;-22.99983;,
 39.99969;11.30012;-22.99983;,
 -40.00031;13.00012;-22.99983;,
 -40.00000;13.00000;-27.00000;,
 -40.00000;11.30000;-27.00000;,
 -40.00031;11.30012;-22.99983;,
 40.00000;13.00000;-27.00000;,
 -40.00000;13.00000;-27.00000;,
 -40.00000;11.30000;-27.00000;,
 40.00000;11.30000;-27.00000;,
 -40.00000;13.00000;23.00000;,
 40.00000;13.00000;23.00000;,
 40.00000;11.30000;23.00000;,
 -40.00000;11.30000;23.00000;,
 40.00000;13.00000;23.00000;,
 39.99969;13.00012;27.00017;,
 39.99969;11.30012;27.00017;,
 40.00000;11.30000;23.00000;,
 39.99969;13.00012;27.00017;,
 -40.00031;13.00012;27.00017;,
 -40.00031;11.30012;27.00017;,
 39.99969;11.30012;27.00017;,
 -40.00031;13.00012;27.00017;,
 -40.00000;13.00000;23.00000;,
 -40.00000;11.30000;23.00000;,
 -40.00031;11.30012;27.00017;,
 40.00000;13.00000;23.00000;,
 -40.00000;13.00000;23.00000;,
 -40.00000;11.30000;23.00000;,
 40.00000;11.30000;23.00000;,
 40.00000;13.00000;23.00000;,
 40.00000;13.00000;-23.00000;,
 40.00000;11.30000;-23.00000;,
 40.00000;11.30000;23.00000;,
 40.00000;13.00000;-23.00000;,
 44.00017;13.00012;-22.99968;,
 44.00017;11.30012;-22.99968;,
 40.00000;11.30000;-23.00000;,
 44.00017;13.00012;-22.99968;,
 44.00017;13.00012;23.00032;,
 44.00017;11.30012;23.00032;,
 44.00017;11.30012;-22.99968;,
 44.00017;13.00012;23.00032;,
 40.00000;13.00000;23.00000;,
 40.00000;11.30000;23.00000;,
 44.00017;11.30012;23.00032;,
 40.00000;13.00000;-23.00000;,
 40.00000;13.00000;23.00000;,
 40.00000;11.30000;23.00000;,
 40.00000;11.30000;-23.00000;,
 -44.00000;13.00000;23.00000;,
 -44.00000;13.00000;-23.00000;,
 -44.00000;11.30000;-23.00000;,
 -44.00000;11.30000;23.00000;,
 -44.00000;13.00000;-23.00000;,
 -39.99983;13.00012;-22.99968;,
 -39.99983;11.30012;-22.99968;,
 -44.00000;11.30000;-23.00000;,
 -39.99983;13.00012;-22.99968;,
 -39.99983;13.00012;23.00032;,
 -39.99983;11.30012;23.00032;,
 -39.99983;11.30012;-22.99968;,
 -39.99983;13.00012;23.00032;,
 -44.00000;13.00000;23.00000;,
 -44.00000;11.30000;23.00000;,
 -39.99983;11.30012;23.00032;,
 -44.00000;13.00000;-23.00000;,
 -44.00000;13.00000;23.00000;,
 -44.00000;11.30000;23.00000;,
 -44.00000;11.30000;-23.00000;,
 -40.00000;40.00000;-27.00000;,
 40.00000;40.00000;-27.00000;,
 40.00000;38.30000;-27.00000;,
 -40.00000;38.30000;-27.00000;,
 40.00000;40.00000;-27.00000;,
 39.99969;40.00012;-22.99983;,
 39.99969;38.30012;-22.99983;,
 40.00000;38.30000;-27.00000;,
 39.99969;40.00012;-22.99983;,
 -40.00031;40.00012;-22.99983;,
 -40.00031;38.30012;-22.99983;,
 39.99969;38.30012;-22.99983;,
 -40.00031;40.00012;-22.99983;,
 -40.00000;40.00000;-27.00000;,
 -40.00000;38.30000;-27.00000;,
 -40.00031;38.30012;-22.99983;,
 40.00000;40.00000;-27.00000;,
 -40.00000;40.00000;-27.00000;,
 -40.00000;38.30000;-27.00000;,
 40.00000;38.30000;-27.00000;,
 -40.00000;40.00000;23.00000;,
 40.00000;40.00000;23.00000;,
 40.00000;38.30000;23.00000;,
 -40.00000;38.30000;23.00000;,
 40.00000;40.00000;23.00000;,
 39.99969;40.00012;27.00017;,
 39.99969;38.30012;27.00017;,
 40.00000;38.30000;23.00000;,
 39.99969;40.00012;27.00017;,
 -40.00031;40.00012;27.00017;,
 -40.00031;38.30012;27.00017;,
 39.99969;38.30012;27.00017;,
 -40.00031;40.00012;27.00017;,
 -40.00000;40.00000;23.00000;,
 -40.00000;38.30000;23.00000;,
 -40.00031;38.30012;27.00017;,
 40.00000;40.00000;23.00000;,
 -40.00000;40.00000;23.00000;,
 -40.00000;38.30000;23.00000;,
 40.00000;38.30000;23.00000;,
 40.00000;40.00000;23.00000;,
 40.00000;40.00000;-23.00000;,
 40.00000;38.30000;-23.00000;,
 40.00000;38.30000;23.00000;,
 40.00000;40.00000;-23.00000;,
 44.00017;40.00012;-22.99968;,
 44.00017;38.30012;-22.99968;,
 40.00000;38.30000;-23.00000;,
 44.00017;40.00012;-22.99968;,
 44.00017;40.00012;23.00032;,
 44.00017;38.30012;23.00032;,
 44.00017;38.30012;-22.99968;,
 44.00017;40.00012;23.00032;,
 40.00000;40.00000;23.00000;,
 40.00000;38.30000;23.00000;,
 44.00017;38.30012;23.00032;,
 40.00000;40.00000;-23.00000;,
 40.00000;40.00000;23.00000;,
 40.00000;38.30000;23.00000;,
 40.00000;38.30000;-23.00000;,
 -44.00000;40.00000;23.00000;,
 -44.00000;40.00000;-23.00000;,
 -44.00000;38.30000;-23.00000;,
 -44.00000;38.30000;23.00000;,
 -44.00000;40.00000;-23.00000;,
 -39.99983;40.00012;-22.99968;,
 -39.99983;38.30012;-22.99968;,
 -44.00000;38.30000;-23.00000;,
 -39.99983;40.00012;-22.99968;,
 -39.99983;40.00012;23.00032;,
 -39.99983;38.30012;23.00032;,
 -39.99983;38.30012;-22.99968;,
 -39.99983;40.00012;23.00032;,
 -44.00000;40.00000;23.00000;,
 -44.00000;38.30000;23.00000;,
 -39.99983;38.30012;23.00032;,
 -44.00000;40.00000;-23.00000;,
 -44.00000;40.00000;23.00000;,
 -44.00000;38.30000;23.00000;,
 -44.00000;38.30000;-23.00000;,
 -43.50000;39.00000;26.50000;,
 -43.50000;39.00000;-26.50000;,
 -43.50000;13.00000;-26.50000;,
 -43.50000;13.00000;26.50000;,
 -43.50000;39.00000;-26.50000;,
 -41.00000;39.00000;-26.50000;,
 -41.00000;13.00000;-26.50000;,
 -43.50000;13.00000;-26.50000;,
 -41.00000;39.00000;-26.50000;,
 -40.50000;39.00000;26.50000;,
 -40.50000;13.00000;26.50000;,
 -41.00000;13.00000;-26.50000;,
 -40.50000;39.00000;26.50000;,
 -43.50000;39.00000;26.50000;,
 -43.50000;13.00000;26.50000;,
 -40.50000;13.00000;26.50000;,
 -43.50000;39.00000;-26.50000;,
 -43.50000;39.00000;26.50000;,
 -43.50000;13.00000;26.50000;,
 -43.50000;13.00000;-26.50000;,
 40.50000;39.00000;26.50000;,
 40.50000;39.00000;-26.50000;,
 40.50000;13.00000;-26.50000;,
 40.50000;13.00000;26.50000;,
 40.50000;39.00000;-26.50000;,
 43.00000;39.00000;-26.50000;,
 43.00000;13.00000;-26.50000;,
 40.50000;13.00000;-26.50000;,
 43.00000;39.00000;-26.50000;,
 43.50000;39.00000;26.50000;,
 43.50000;13.00000;26.50000;,
 43.00000;13.00000;-26.50000;,
 43.50000;39.00000;26.50000;,
 40.50000;39.00000;26.50000;,
 40.50000;13.00000;26.50000;,
 43.50000;13.00000;26.50000;,
 40.50000;39.00000;-26.50000;,
 40.50000;39.00000;26.50000;,
 40.50000;13.00000;26.50000;,
 40.50000;13.00000;-26.50000;,
 -40.00000;39.50000;23.50000;,
 40.00000;39.50000;23.50000;,
 40.00000;39.50000;-23.50000;,
 -40.00000;39.50000;-23.50000;,
 40.00000;39.50000;23.50000;,
 40.00000;38.50000;23.50000;,
 40.00000;38.50000;-23.50000;,
 40.00000;39.50000;-23.50000;,
 40.00000;38.50000;23.50000;,
 -40.00000;38.50000;23.50000;,
 -40.00000;38.50000;-23.50000;,
 40.00000;38.50000;-23.50000;,
 -40.00000;38.50000;23.50000;,
 -40.00000;39.50000;23.50000;,
 -40.00000;39.50000;-23.50000;,
 -40.00000;38.50000;-23.50000;,
 40.00000;39.50000;23.50000;,
 -40.00000;39.50000;23.50000;,
 -40.00000;39.50000;-23.50000;,
 40.00000;39.50000;-23.50000;,
 -40.00000;39.00000;-26.50000;,
 40.00000;39.00000;-26.50000;,
 40.00000;13.00000;-26.50000;,
 -40.00000;13.00000;-26.50000;,
 40.00000;39.00000;-26.50000;,
 40.00000;39.00000;-23.50000;,
 40.00000;13.00000;-23.50000;,
 40.00000;13.00000;-26.50000;,
 40.00000;39.00000;-23.50000;,
 -40.00000;39.00000;-23.50000;,
 -40.00000;13.00000;-23.50000;,
 40.00000;13.00000;-23.50000;,
 -40.00000;39.00000;-23.50000;,
 -40.00000;39.00000;-26.50000;,
 -40.00000;13.00000;-26.50000;,
 -40.00000;13.00000;-23.50000;,
 40.00000;39.00000;-26.50000;,
 -40.00000;39.00000;-26.50000;,
 -40.00000;13.00000;-26.50000;,
 40.00000;13.00000;-26.50000;,
 -40.00000;39.00000;23.50000;,
 40.00000;39.00000;23.50000;,
 40.00000;13.00000;23.50000;,
 -40.00000;13.00000;23.50000;,
 40.00000;39.00000;23.50000;,
 40.00000;39.00000;26.50000;,
 40.00000;13.00000;26.50000;,
 40.00000;13.00000;23.50000;,
 40.00000;39.00000;26.50000;,
 -40.00000;39.00000;26.50000;,
 -40.00000;13.00000;26.50000;,
 40.00000;13.00000;26.50000;,
 -40.00000;39.00000;26.50000;,
 -40.00000;39.00000;23.50000;,
 -40.00000;13.00000;23.50000;,
 -40.00000;13.00000;26.50000;,
 40.00000;39.00000;23.50000;,
 -40.00000;39.00000;23.50000;,
 -40.00000;13.00000;23.50000;,
 40.00000;13.00000;23.50000;;
 
 136;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;8,11,12,13;,
 4;14,15,7,16;,
 4;14,16,0,17;,
 4;18,19,1,20;,
 4;18,20,6,21;,
 4;22,23,24,25;,
 4;22,25,26,27;,
 4;28,29,30,31;,
 4;32,33,34,35;,
 4;36,37,38,39;,
 4;40,41,42,43;,
 4;40,33,44,45;,
 4;46,47,34,43;,
 4;48,49,50,51;,
 4;52,53,54,55;,
 4;56,57,58,59;,
 4;60,61,62,63;,
 4;60,53,64,65;,
 4;66,67,54,63;,
 4;68,69,70,71;,
 4;72,73,74,75;,
 4;76,77,78,79;,
 4;80,81,82,83;,
 4;80,73,84,85;,
 4;86,87,74,83;,
 4;88,89,90,91;,
 4;92,93,94,95;,
 4;96,97,98,99;,
 4;100,101,102,103;,
 4;100,93,104,105;,
 4;106,107,94,103;,
 4;108,109,110,111;,
 4;112,113,114,115;,
 4;116,117,118,119;,
 4;120,121,122,123;,
 4;120,113,124,125;,
 4;126,127,114,123;,
 4;128,129,130,131;,
 4;132,133,134,135;,
 4;136,137,138,139;,
 4;140,141,142,143;,
 4;140,133,144,145;,
 4;146,147,134,143;,
 4;148,149,150,151;,
 4;152,153,154,155;,
 4;156,157,158,159;,
 4;160,161,162,163;,
 4;160,153,164,165;,
 4;166,167,154,163;,
 4;168,169,170,171;,
 4;172,173,174,175;,
 4;176,177,178,179;,
 4;180,181,182,183;,
 4;180,173,184,185;,
 4;186,187,174,183;,
 4;188,189,190,191;,
 4;192,193,194,195;,
 4;196,197,198,199;,
 4;200,201,202,203;,
 4;200,193,204,205;,
 4;206,207,194,203;,
 4;208,209,210,211;,
 4;212,213,214,215;,
 4;216,217,218,219;,
 4;220,221,222,223;,
 4;220,213,224,225;,
 4;226,227,214,223;,
 4;228,229,230,231;,
 4;232,233,234,235;,
 4;236,237,238,239;,
 4;240,241,242,243;,
 4;240,233,244,245;,
 4;246,247,234,243;,
 4;248,249,250,251;,
 4;252,253,254,255;,
 4;256,257,258,259;,
 4;260,261,262,263;,
 4;260,253,264,265;,
 4;266,267,254,263;,
 4;268,269,270,271;,
 4;272,273,274,275;,
 4;276,277,278,279;,
 4;280,281,282,283;,
 4;280,273,284,285;,
 4;286,287,274,283;,
 4;288,289,290,291;,
 4;292,293,294,295;,
 4;296,297,298,299;,
 4;300,301,302,303;,
 4;300,293,304,305;,
 4;306,307,294,303;,
 4;308,309,310,311;,
 4;312,313,314,315;,
 4;316,317,318,319;,
 4;320,321,322,323;,
 4;320,313,324,325;,
 4;326,327,314,323;,
 4;328,329,330,331;,
 4;332,333,334,335;,
 4;336,337,338,339;,
 4;340,341,342,343;,
 4;340,333,344,345;,
 4;346,347,334,343;,
 4;348,349,350,351;,
 4;352,353,354,355;,
 4;356,357,358,359;,
 4;360,361,362,363;,
 4;360,353,364,365;,
 4;366,367,354,363;,
 4;368,369,370,371;,
 4;372,373,374,375;,
 4;376,377,378,379;,
 4;380,381,382,383;,
 4;380,373,384,385;,
 4;386,387,374,383;,
 4;388,389,390,391;,
 4;392,393,394,395;,
 4;396,397,398,399;,
 4;400,401,402,403;,
 4;400,393,404,405;,
 4;406,407,394,403;,
 4;408,409,410,411;,
 4;412,413,414,415;,
 4;416,417,418,419;,
 4;420,421,422,423;,
 4;420,413,424,425;,
 4;426,427,414,423;,
 4;428,429,430,431;,
 4;432,433,434,435;,
 4;436,437,438,439;,
 4;440,441,442,443;,
 4;440,433,444,445;,
 4;446,447,434,443;;
 
 MeshMaterialList {
  4;
  136;
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
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  0,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\woodboard001.png";
   }
  }
  Material {
   0.298400;0.298400;0.298400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\woodboard001.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;0.330000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\MapObj\\Glass.png";
   }
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  62;
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  -1.000000;-0.000522;0.000040;,
  1.000000;0.000000;-0.000056;,
  -1.000000;-0.000006;0.000056;,
  -1.000000;-0.001039;0.000024;,
  -0.000001;0.000058;1.000000;,
  0.000000;-0.000000;1.000000;,
  -0.000002;0.000116;1.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;-0.000012;-0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000012;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.000043;0.000000;-1.000000;,
  1.000000;0.000000;0.000078;,
  0.000042;0.000000;1.000000;,
  -0.000042;0.000000;-1.000000;,
  1.000000;0.000000;0.000078;,
  0.000043;0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000080;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  -1.000000;0.000000;-0.000078;,
  0.000030;1.000000;-0.000030;,
  -0.000030;-1.000000;0.000030;,
  -1.000000;0.000000;-0.000078;,
  0.000000;1.000000;-0.000030;,
  0.000000;-1.000000;0.000030;,
  0.000000;1.000000;-0.000030;,
  0.000000;-1.000000;0.000030;,
  -0.000080;0.000000;1.000000;,
  -0.000030;1.000000;0.000000;,
  0.000030;-1.000000;-0.000000;,
  0.000000;1.000000;-0.000030;,
  0.000000;-1.000000;0.000030;,
  0.000000;1.000000;-0.000030;,
  0.000000;-1.000000;0.000030;,
  -0.000030;1.000000;0.000000;,
  0.000030;-1.000000;-0.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.999955;0.000000;-0.009434;,
  0.000000;0.000000;1.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;;
  136;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;3,5,5,3;,
  4;3,3,6,6;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;7,8,8,7;,
  4;7,7,9,9;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;16,16,16,16;,
  4;17,17,17,17;,
  4;18,18,18,18;,
  4;27,27,27,27;,
  4;28,28,28,28;,
  4;29,29,29,29;,
  4;19,19,19,19;,
  4;20,20,20,20;,
  4;21,21,21,21;,
  4;30,30,30,30;,
  4;28,28,28,28;,
  4;29,29,29,29;,
  4;16,16,16,16;,
  4;17,17,17,17;,
  4;18,18,18,18;,
  4;27,27,27,27;,
  4;28,28,28,28;,
  4;29,29,29,29;,
  4;19,19,19,19;,
  4;20,20,20,20;,
  4;21,21,21,21;,
  4;30,30,30,30;,
  4;28,28,28,28;,
  4;29,29,29,29;,
  4;22,22,22,22;,
  4;20,20,20,20;,
  4;23,23,23,23;,
  4;27,27,27,27;,
  4;31,31,31,31;,
  4;32,32,32,32;,
  4;22,22,22,22;,
  4;17,17,17,17;,
  4;23,23,23,23;,
  4;30,30,30,30;,
  4;33,33,33,33;,
  4;34,34,34,34;,
  4;24,24,24,24;,
  4;25,25,25,25;,
  4;26,26,26,26;,
  4;35,35,35,35;,
  4;36,36,36,36;,
  4;37,37,37,37;,
  4;24,24,24,24;,
  4;25,25,25,25;,
  4;26,26,26,26;,
  4;35,35,35,35;,
  4;36,36,36,36;,
  4;37,37,37,37;,
  4;22,22,22,22;,
  4;20,20,20,20;,
  4;23,23,23,23;,
  4;27,27,27,27;,
  4;38,38,38,38;,
  4;39,39,39,39;,
  4;22,22,22,22;,
  4;17,17,17,17;,
  4;23,23,23,23;,
  4;30,30,30,30;,
  4;40,40,40,40;,
  4;41,41,41,41;,
  4;24,24,24,24;,
  4;25,25,25,25;,
  4;26,26,26,26;,
  4;35,35,35,35;,
  4;42,42,42,42;,
  4;43,43,43,43;,
  4;24,24,24,24;,
  4;25,25,25,25;,
  4;26,26,26,26;,
  4;35,35,35,35;,
  4;42,42,42,42;,
  4;43,43,43,43;,
  4;44,44,44,44;,
  4;45,45,45,45;,
  4;46,46,46,46;,
  4;47,47,47,47;,
  4;48,48,48,48;,
  4;49,49,49,49;,
  4;44,44,44,44;,
  4;45,45,45,45;,
  4;46,46,46,46;,
  4;47,47,47,47;,
  4;48,48,48,48;,
  4;49,49,49,49;,
  4;50,50,50,50;,
  4;51,51,51,51;,
  4;52,52,52,52;,
  4;53,53,53,53;,
  4;54,54,54,54;,
  4;55,55,55,55;,
  4;56,56,56,56;,
  4;57,57,57,57;,
  4;58,58,58,58;,
  4;59,59,59,59;,
  4;60,60,60,60;,
  4;61,61,61,61;,
  4;56,56,56,56;,
  4;57,57,57,57;,
  4;58,58,58,58;,
  4;59,59,59,59;,
  4;60,60,60,60;,
  4;61,61,61,61;;
 }
 MeshTextureCoords {
  448;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.500000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  0.000000;0.500000;,
  0.000000;0.000000;,
  1.000000;0.500000;,
  0.000000;1.000000;,
  1.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.500000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;;
 }
}
