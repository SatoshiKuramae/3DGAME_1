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
 192;
 0.04239;4.13955;0.26922;,
 1.85379;3.66673;-1.39492;,
 0.04239;3.66673;-2.08424;,
 0.04239;4.13955;0.26922;,
 2.60410;3.66673;0.26922;,
 0.04239;4.13955;0.26922;,
 1.85379;3.66673;1.93337;,
 0.04239;4.13955;0.26922;,
 0.04239;3.66673;2.62268;,
 0.04239;4.13955;0.26922;,
 -1.76901;3.66673;1.93337;,
 0.04239;4.13955;0.26922;,
 -2.51932;3.66673;0.26922;,
 0.04239;4.13955;0.26922;,
 -1.76901;3.66673;-1.39492;,
 0.04239;4.13955;0.26922;,
 0.04239;3.66673;-2.08424;,
 3.38942;2.32024;-2.80572;,
 0.04239;2.32024;-4.07940;,
 4.77581;2.32024;0.26922;,
 3.38942;2.32024;3.34416;,
 0.04239;2.32024;4.61785;,
 -3.30464;2.32024;3.34416;,
 -4.69103;2.32024;0.26922;,
 -3.30464;2.32024;-2.80572;,
 0.04239;2.32024;-4.07940;,
 4.41550;0.30507;-3.74838;,
 0.04239;0.30507;-5.41253;,
 6.22690;0.30507;0.26922;,
 4.41550;0.30507;4.28683;,
 0.04239;0.30507;5.95097;,
 -4.33072;0.30507;4.28682;,
 -6.14212;0.30507;0.26922;,
 -4.33072;0.30507;-3.74838;,
 0.04239;0.30507;-5.41253;,
 4.77581;-2.07198;-4.07940;,
 0.04239;-2.07198;-5.88066;,
 6.73646;-2.07198;0.26922;,
 4.77581;-2.07198;4.61785;,
 0.04239;-2.07198;6.41911;,
 -4.69103;-2.07198;4.61784;,
 -6.65167;-2.07198;0.26922;,
 -4.69103;-2.07198;-4.07940;,
 0.04239;-2.07198;-5.88066;,
 4.41550;-4.44904;-3.74838;,
 0.04239;-4.44904;-5.41253;,
 6.22690;-4.44904;0.26922;,
 4.41550;-4.44904;4.28683;,
 0.04239;-4.44904;5.95097;,
 -4.33072;-4.44904;4.28682;,
 -6.14212;-4.44904;0.26922;,
 -4.33072;-4.44904;-3.74838;,
 0.04239;-4.44904;-5.41253;,
 3.38942;-6.46420;-2.80572;,
 0.04239;-6.46420;-4.07940;,
 4.77581;-6.46420;0.26922;,
 3.38942;-6.46420;3.34416;,
 0.04239;-6.46420;4.61785;,
 -3.30464;-6.46420;3.34416;,
 -4.69103;-6.46420;0.26922;,
 -3.30464;-6.46420;-2.80572;,
 0.04239;-6.46420;-4.07940;,
 1.85379;-7.81069;-1.39492;,
 0.04239;-7.81069;-2.08424;,
 2.60410;-7.81069;0.26922;,
 1.85379;-7.81069;1.93337;,
 0.04239;-7.81069;2.62268;,
 -1.76901;-7.81069;1.93337;,
 -2.51932;-7.81069;0.26922;,
 -1.76901;-7.81069;-1.39492;,
 0.04239;-7.81069;-2.08424;,
 0.04239;-8.28352;0.26922;,
 0.04239;-8.28352;0.26922;,
 0.04239;-8.28352;0.26922;,
 0.04239;-8.28352;0.26922;,
 0.04239;-8.28352;0.26922;,
 0.04239;-8.28352;0.26922;,
 0.04239;-8.28352;0.26922;,
 0.04239;-8.28352;0.26922;,
 -0.40463;-4.02736;-5.70771;,
 3.34501;-5.75236;-4.15505;,
 4.71994;-22.96288;-4.52240;,
 -0.40463;-22.96288;-6.70880;,
 5.66769;-5.75236;0.03347;,
 6.09307;-22.96288;0.03347;,
 3.67106;-5.75236;3.82567;,
 4.40036;-22.96288;3.72783;,
 -0.40463;-3.77503;6.23881;,
 -0.40463;-22.96288;5.69429;,
 -4.51383;-2.65618;5.07227;,
 -5.14230;-22.96288;4.32344;,
 -6.74660;-2.15619;0.03347;,
 -6.79409;-22.96288;0.03347;,
 -5.45420;-1.83450;-3.80295;,
 -5.74207;-22.96288;-4.01621;,
 -0.40463;-4.02736;-5.70771;,
 -0.40463;-22.96288;-6.70880;,
 -0.40463;-5.75236;0.03347;,
 -0.40463;-5.75236;0.03347;,
 -0.40463;-5.75236;0.03347;,
 -0.40463;-5.75236;0.03347;,
 -0.40463;-5.75236;0.03347;,
 -0.40463;-5.75236;0.03347;,
 -0.40463;-5.75236;0.03347;,
 -0.40463;-5.75236;0.03347;,
 -0.40463;-22.96288;0.03347;,
 -0.40463;-22.96288;0.03347;,
 -0.40463;-22.96288;0.03347;,
 -0.40463;-22.96288;0.03347;,
 -0.40463;-22.96288;0.03347;,
 -0.40463;-22.96288;0.03347;,
 -0.40463;-22.96288;0.03347;,
 -0.40463;-22.96288;0.03347;,
 -0.36448;-18.40610;-0.23404;,
 1.24013;-18.82705;-1.84667;,
 -0.36448;-18.82705;-2.51465;,
 -0.36448;-18.40610;-0.23404;,
 1.90478;-18.82705;-0.23404;,
 -0.36448;-18.40610;-0.23404;,
 1.24013;-18.82705;1.37859;,
 -0.36448;-18.40610;-0.23404;,
 -0.36448;-18.82705;2.04657;,
 -0.36448;-18.40610;-0.23404;,
 -1.96909;-18.82705;1.37859;,
 -0.36448;-18.40610;-0.23404;,
 -2.63374;-18.82705;-0.23404;,
 -0.36448;-18.40610;-0.23404;,
 -1.96909;-18.82705;-1.84667;,
 -0.36448;-18.40610;-0.23404;,
 -0.36448;-18.82705;-2.51465;,
 2.60045;-20.02579;-3.21380;,
 -0.36448;-20.02579;-4.44805;,
 3.82857;-20.02579;-0.23404;,
 2.60045;-20.02579;2.74572;,
 -0.36448;-20.02579;3.97998;,
 -3.32941;-20.02579;2.74572;,
 -4.55753;-20.02579;-0.23404;,
 -3.32941;-20.02579;-3.21380;,
 -0.36448;-20.02579;-4.44805;,
 3.50939;-21.81985;-4.12728;,
 -0.36448;-21.81985;-5.73991;,
 5.11400;-21.81985;-0.23404;,
 3.50939;-21.81985;3.65920;,
 -0.36448;-21.81985;5.27184;,
 -4.23835;-21.81985;3.65920;,
 -5.84296;-21.81985;-0.23404;,
 -4.23835;-21.81985;-4.12728;,
 -0.36448;-21.81985;-5.73991;,
 3.82857;-23.93607;-4.44805;,
 -0.36448;-23.93607;-6.19356;,
 5.56538;-23.93607;-0.23404;,
 3.82857;-23.93607;3.97998;,
 -0.36448;-23.93607;5.72548;,
 -4.55753;-23.93607;3.97997;,
 -6.29435;-23.93607;-0.23404;,
 -4.55753;-23.93607;-4.44805;,
 -0.36448;-23.93607;-6.19356;,
 3.50939;-26.05228;-4.12728;,
 -0.36448;-26.05228;-5.73991;,
 5.11400;-26.05228;-0.23404;,
 3.50939;-26.05228;3.65920;,
 -0.36448;-26.05228;5.27184;,
 -4.23835;-26.05228;3.65920;,
 -5.84296;-26.05228;-0.23404;,
 -4.23835;-26.05228;-4.12728;,
 -0.36448;-26.05228;-5.73991;,
 2.60045;-27.84631;-3.21380;,
 -0.36448;-27.84631;-4.44805;,
 3.82857;-27.84631;-0.23404;,
 2.60045;-27.84631;2.74572;,
 -0.36448;-27.84631;3.97998;,
 -3.32941;-27.84631;2.74572;,
 -4.55753;-27.84631;-0.23404;,
 -3.32941;-27.84631;-3.21380;,
 -0.36448;-27.84631;-4.44805;,
 1.24013;-29.04507;-1.84667;,
 -0.36448;-29.04507;-2.51465;,
 1.90478;-29.04507;-0.23404;,
 1.24013;-29.04507;1.37860;,
 -0.36448;-29.04507;2.04657;,
 -1.96909;-29.04507;1.37859;,
 -2.63374;-29.04507;-0.23404;,
 -1.96909;-29.04507;-1.84667;,
 -0.36448;-29.04507;-2.51465;,
 -0.36448;-29.46601;-0.23404;,
 -0.36448;-29.46601;-0.23404;,
 -0.36448;-29.46601;-0.23404;,
 -0.36448;-29.46601;-0.23404;,
 -0.36448;-29.46601;-0.23404;,
 -0.36448;-29.46601;-0.23404;,
 -0.36448;-29.46601;-0.23404;,
 -0.36448;-29.46601;-0.23404;;
 
 152;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 3;9,10,8;,
 3;11,12,10;,
 3;13,14,12;,
 3;15,16,14;,
 4;2,1,17,18;,
 4;1,4,19,17;,
 4;4,6,20,19;,
 4;6,8,21,20;,
 4;8,10,22,21;,
 4;10,12,23,22;,
 4;12,14,24,23;,
 4;14,16,25,24;,
 4;18,17,26,27;,
 4;17,19,28,26;,
 4;19,20,29,28;,
 4;20,21,30,29;,
 4;21,22,31,30;,
 4;22,23,32,31;,
 4;23,24,33,32;,
 4;24,25,34,33;,
 4;27,26,35,36;,
 4;26,28,37,35;,
 4;28,29,38,37;,
 4;29,30,39,38;,
 4;30,31,40,39;,
 4;31,32,41,40;,
 4;32,33,42,41;,
 4;33,34,43,42;,
 4;36,35,44,45;,
 4;35,37,46,44;,
 4;37,38,47,46;,
 4;38,39,48,47;,
 4;39,40,49,48;,
 4;40,41,50,49;,
 4;41,42,51,50;,
 4;42,43,52,51;,
 4;45,44,53,54;,
 4;44,46,55,53;,
 4;46,47,56,55;,
 4;47,48,57,56;,
 4;48,49,58,57;,
 4;49,50,59,58;,
 4;50,51,60,59;,
 4;51,52,61,60;,
 4;54,53,62,63;,
 4;53,55,64,62;,
 4;55,56,65,64;,
 4;56,57,66,65;,
 4;57,58,67,66;,
 4;58,59,68,67;,
 4;59,60,69,68;,
 4;60,61,70,69;,
 3;63,62,71;,
 3;62,64,72;,
 3;64,65,73;,
 3;65,66,74;,
 3;66,67,75;,
 3;67,68,76;,
 3;68,69,77;,
 3;69,70,78;,
 4;79,80,81,82;,
 4;80,83,84,81;,
 4;83,85,86,84;,
 4;85,87,88,86;,
 4;87,89,90,88;,
 4;89,91,92,90;,
 4;91,93,94,92;,
 4;93,95,96,94;,
 3;97,80,79;,
 3;98,83,80;,
 3;99,85,83;,
 3;100,87,85;,
 3;101,89,87;,
 3;102,91,89;,
 3;103,93,91;,
 3;104,95,93;,
 3;105,82,81;,
 3;106,81,84;,
 3;107,84,86;,
 3;108,86,88;,
 3;109,88,90;,
 3;110,90,92;,
 3;111,92,94;,
 3;112,94,96;,
 3;113,114,115;,
 3;116,117,114;,
 3;118,119,117;,
 3;120,121,119;,
 3;122,123,121;,
 3;124,125,123;,
 3;126,127,125;,
 3;128,129,127;,
 4;115,114,130,131;,
 4;114,117,132,130;,
 4;117,119,133,132;,
 4;119,121,134,133;,
 4;121,123,135,134;,
 4;123,125,136,135;,
 4;125,127,137,136;,
 4;127,129,138,137;,
 4;131,130,139,140;,
 4;130,132,141,139;,
 4;132,133,142,141;,
 4;133,134,143,142;,
 4;134,135,144,143;,
 4;135,136,145,144;,
 4;136,137,146,145;,
 4;137,138,147,146;,
 4;140,139,148,149;,
 4;139,141,150,148;,
 4;141,142,151,150;,
 4;142,143,152,151;,
 4;143,144,153,152;,
 4;144,145,154,153;,
 4;145,146,155,154;,
 4;146,147,156,155;,
 4;149,148,157,158;,
 4;148,150,159,157;,
 4;150,151,160,159;,
 4;151,152,161,160;,
 4;152,153,162,161;,
 4;153,154,163,162;,
 4;154,155,164,163;,
 4;155,156,165,164;,
 4;158,157,166,167;,
 4;157,159,168,166;,
 4;159,160,169,168;,
 4;160,161,170,169;,
 4;161,162,171,170;,
 4;162,163,172,171;,
 4;163,164,173,172;,
 4;164,165,174,173;,
 4;167,166,175,176;,
 4;166,168,177,175;,
 4;168,169,178,177;,
 4;169,170,179,178;,
 4;170,171,180,179;,
 4;171,172,181,180;,
 4;172,173,182,181;,
 4;173,174,183,182;,
 3;176,175,184;,
 3;175,177,185;,
 3;177,178,186;,
 3;178,179,187;,
 3;179,180,188;,
 3;180,181,189;,
 3;181,182,190;,
 3;182,183,191;;
 
 MeshMaterialList {
  4;
  152;
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
   0.203922;0.272941;0.501961;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.018824;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  134;
  0.000000;1.000000;0.000000;,
  0.000000;0.923370;-0.383910;,
  0.252173;0.928444;-0.272764;,
  0.358341;0.933591;0.000000;,
  0.252173;0.928444;0.272764;,
  0.000000;0.923370;0.383910;,
  -0.252173;0.928444;0.272764;,
  -0.358341;0.933591;0.000000;,
  -0.252173;0.928444;-0.272763;,
  0.000000;0.705663;-0.708548;,
  0.473509;0.719290;-0.508341;,
  0.679701;0.733490;0.000000;,
  0.473509;0.719290;0.508341;,
  -0.000000;0.705663;0.708548;,
  -0.473509;0.719290;0.508341;,
  -0.679701;0.733490;0.000000;,
  -0.473509;0.719290;-0.508341;,
  0.000000;0.381256;-0.924470;,
  0.628824;0.394184;-0.670223;,
  0.912948;0.408075;0.000000;,
  0.628824;0.394185;0.670223;,
  -0.000000;0.381256;0.924469;,
  -0.628824;0.394184;0.670223;,
  -0.912949;0.408075;0.000000;,
  -0.628824;0.394184;-0.670223;,
  0.000000;0.000000;-1.000000;,
  0.685282;0.000000;-0.728278;,
  1.000000;0.000000;0.000000;,
  0.685282;0.000000;0.728278;,
  -0.000000;0.000000;1.000000;,
  -0.685283;0.000000;0.728277;,
  -1.000000;0.000000;0.000000;,
  -0.685282;0.000000;-0.728278;,
  0.000000;-0.381257;-0.924469;,
  0.628824;-0.394185;-0.670223;,
  0.912948;-0.408076;0.000000;,
  0.628824;-0.394185;0.670223;,
  -0.000000;-0.381257;0.924469;,
  -0.628824;-0.394185;0.670223;,
  -0.912948;-0.408075;0.000000;,
  -0.628824;-0.394185;-0.670223;,
  0.000000;-0.705664;-0.708547;,
  0.473508;-0.719291;-0.508341;,
  0.679700;-0.733490;0.000000;,
  0.473508;-0.719291;0.508341;,
  -0.000000;-0.705664;0.708547;,
  -0.473509;-0.719291;0.508341;,
  -0.679700;-0.733490;0.000000;,
  -0.473508;-0.719291;-0.508341;,
  0.000000;-0.923370;-0.383912;,
  0.252174;-0.928444;-0.272765;,
  0.358343;-0.933590;0.000000;,
  0.252174;-0.928444;0.272765;,
  0.000000;-0.923370;0.383912;,
  -0.252174;-0.928444;0.272765;,
  -0.358343;-0.933590;0.000000;,
  -0.252174;-0.928444;-0.272765;,
  0.000000;-1.000000;0.000000;,
  0.305512;0.952165;0.006677;,
  -0.001581;0.043803;-0.999039;,
  0.709142;0.054816;-0.702932;,
  0.998591;0.044396;0.029064;,
  0.706748;0.011494;0.707372;,
  0.086815;-0.018174;0.996059;,
  -0.667270;-0.010059;0.744748;,
  -0.998615;0.009567;0.051734;,
  -0.748832;0.022003;-0.662395;,
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;-0.000000;,
  -0.000000;0.933473;-0.358648;,
  0.254714;0.933188;-0.253536;,
  0.360125;0.932904;0.000000;,
  0.254714;0.933188;0.253536;,
  -0.000000;0.933473;0.358648;,
  -0.254714;0.933188;0.253536;,
  -0.360125;0.932904;0.000000;,
  -0.254714;0.933188;-0.253536;,
  0.000000;0.733162;-0.680054;,
  0.482491;0.732359;-0.480470;,
  0.681778;0.731559;0.000000;,
  0.482491;0.732359;0.480470;,
  -0.000000;0.733162;0.680055;,
  -0.482492;0.732359;0.480470;,
  -0.681778;0.731559;0.000000;,
  -0.482491;0.732360;-0.480470;,
  0.000000;0.407751;-0.913093;,
  0.647121;0.406948;-0.644692;,
  0.913808;0.406147;0.000000;,
  0.647121;0.406948;0.644692;,
  0.000000;0.407751;0.913093;,
  -0.647121;0.406948;0.644691;,
  -0.913807;0.406148;0.000000;,
  -0.647121;0.406948;-0.644691;,
  0.000000;0.000000;-1.000000;,
  0.708372;0.000000;-0.705839;,
  1.000000;0.000000;0.000000;,
  0.708372;0.000000;0.705839;,
  0.000000;0.000000;1.000000;,
  -0.708372;0.000000;0.705839;,
  -1.000000;0.000000;0.000000;,
  -0.708372;0.000000;-0.705839;,
  0.000000;-0.407755;-0.913091;,
  0.647120;-0.406952;-0.644691;,
  0.913806;-0.406151;0.000000;,
  0.647120;-0.406952;0.644691;,
  0.000000;-0.407755;0.913091;,
  -0.647120;-0.406952;0.644690;,
  -0.913806;-0.406152;0.000000;,
  -0.647120;-0.406952;-0.644690;,
  0.000000;-0.733162;-0.680054;,
  0.482491;-0.732360;-0.480470;,
  0.681778;-0.731560;0.000000;,
  0.482491;-0.732360;0.480470;,
  -0.000000;-0.733162;0.680054;,
  -0.482491;-0.732360;0.480470;,
  -0.681778;-0.731559;0.000000;,
  -0.482491;-0.732360;-0.480470;,
  -0.000000;-0.933473;-0.358649;,
  0.254714;-0.933188;-0.253536;,
  0.360125;-0.932904;0.000000;,
  0.254714;-0.933188;0.253536;,
  -0.000000;-0.933473;0.358649;,
  -0.254714;-0.933188;0.253536;,
  -0.360125;-0.932904;0.000000;,
  -0.254714;-0.933188;-0.253536;,
  -0.000000;-1.000000;-0.000000;,
  0.156498;0.977691;0.140100;,
  0.386660;0.883217;0.265373;,
  0.000000;1.000000;0.000000;,
  0.138841;0.979008;-0.149220;,
  0.299378;0.909096;-0.289685;,
  0.410512;0.887248;-0.210409;,
  0.492604;0.868724;0.051583;,
  0.472136;0.847166;0.243717;;
  152;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,8,7;,
  3;0,1,8;,
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,8,16,15;,
  4;8,1,9,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,16,24,23;,
  4;16,9,17,24;,
  4;17,18,26,25;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,23,31,30;,
  4;23,24,32,31;,
  4;24,17,25,32;,
  4;25,26,34,33;,
  4;26,27,35,34;,
  4;27,28,36,35;,
  4;28,29,37,36;,
  4;29,30,38,37;,
  4;30,31,39,38;,
  4;31,32,40,39;,
  4;32,25,33,40;,
  4;33,34,42,41;,
  4;34,35,43,42;,
  4;35,36,44,43;,
  4;36,37,45,44;,
  4;37,38,46,45;,
  4;38,39,47,46;,
  4;39,40,48,47;,
  4;40,33,41,48;,
  4;41,42,50,49;,
  4;42,43,51,50;,
  4;43,44,52,51;,
  4;44,45,53,52;,
  4;45,46,54,53;,
  4;46,47,55,54;,
  4;47,48,56,55;,
  4;48,41,49,56;,
  3;49,50,57;,
  3;50,51,57;,
  3;51,52,57;,
  3;52,53,57;,
  3;53,54,57;,
  3;54,55,57;,
  3;55,56,57;,
  3;56,49,57;,
  4;59,60,60,59;,
  4;60,61,61,60;,
  4;61,62,62,61;,
  4;62,63,63,62;,
  4;63,64,64,63;,
  4;64,65,65,64;,
  4;65,66,66,65;,
  4;66,59,59,66;,
  3;58,126,127;,
  3;58,128,126;,
  3;58,129,128;,
  3;58,130,129;,
  3;58,131,130;,
  3;58,132,131;,
  3;58,133,132;,
  3;58,127,133;,
  3;67,67,67;,
  3;67,67,67;,
  3;67,67,67;,
  3;67,67,67;,
  3;67,67,67;,
  3;67,67,67;,
  3;67,67,67;,
  3;67,67,67;,
  3;68,70,69;,
  3;68,71,70;,
  3;68,72,71;,
  3;68,73,72;,
  3;68,74,73;,
  3;68,75,74;,
  3;68,76,75;,
  3;68,69,76;,
  4;69,70,78,77;,
  4;70,71,79,78;,
  4;71,72,80,79;,
  4;72,73,81,80;,
  4;73,74,82,81;,
  4;74,75,83,82;,
  4;75,76,84,83;,
  4;76,69,77,84;,
  4;77,78,86,85;,
  4;78,79,87,86;,
  4;79,80,88,87;,
  4;80,81,89,88;,
  4;81,82,90,89;,
  4;82,83,91,90;,
  4;83,84,92,91;,
  4;84,77,85,92;,
  4;85,86,94,93;,
  4;86,87,95,94;,
  4;87,88,96,95;,
  4;88,89,97,96;,
  4;89,90,98,97;,
  4;90,91,99,98;,
  4;91,92,100,99;,
  4;92,85,93,100;,
  4;93,94,102,101;,
  4;94,95,103,102;,
  4;95,96,104,103;,
  4;96,97,105,104;,
  4;97,98,106,105;,
  4;98,99,107,106;,
  4;99,100,108,107;,
  4;100,93,101,108;,
  4;101,102,110,109;,
  4;102,103,111,110;,
  4;103,104,112,111;,
  4;104,105,113,112;,
  4;105,106,114,113;,
  4;106,107,115,114;,
  4;107,108,116,115;,
  4;108,101,109,116;,
  4;109,110,118,117;,
  4;110,111,119,118;,
  4;111,112,120,119;,
  4;112,113,121,120;,
  4;113,114,122,121;,
  4;114,115,123,122;,
  4;115,116,124,123;,
  4;116,109,117,124;,
  3;117,118,125;,
  3;118,119,125;,
  3;119,120,125;,
  3;120,121,125;,
  3;121,122,125;,
  3;122,123,125;,
  3;123,124,125;,
  3;124,117,125;;
 }
 MeshTextureCoords {
  192;
  0.062500;0.000000;,
  0.125000;0.125000;,
  0.000000;0.125000;,
  0.187500;0.000000;,
  0.250000;0.125000;,
  0.312500;0.000000;,
  0.375000;0.125000;,
  0.437500;0.000000;,
  0.500000;0.125000;,
  0.562500;0.000000;,
  0.625000;0.125000;,
  0.687500;0.000000;,
  0.750000;0.125000;,
  0.812500;0.000000;,
  0.875000;0.125000;,
  0.937500;0.000000;,
  1.000000;0.125000;,
  0.125000;0.250000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  1.000000;0.250000;,
  0.125000;0.375000;,
  0.000000;0.375000;,
  0.250000;0.375000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.750000;0.375000;,
  0.875000;0.375000;,
  1.000000;0.375000;,
  0.125000;0.500000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;,
  0.125000;0.625000;,
  0.000000;0.625000;,
  0.250000;0.625000;,
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.750000;0.625000;,
  0.875000;0.625000;,
  1.000000;0.625000;,
  0.125000;0.750000;,
  0.000000;0.750000;,
  0.250000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.750000;0.750000;,
  0.875000;0.750000;,
  1.000000;0.750000;,
  0.125000;0.875000;,
  0.000000;0.875000;,
  0.250000;0.875000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.750000;0.875000;,
  0.875000;0.875000;,
  1.000000;0.875000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;,
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
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
  0.187500;0.000000;,
  0.312500;0.000000;,
  0.437500;0.000000;,
  0.562500;0.000000;,
  0.687500;0.000000;,
  0.812500;0.000000;,
  0.937500;0.000000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;,
  0.062500;0.000000;,
  0.125000;0.125000;,
  0.000000;0.125000;,
  0.187500;0.000000;,
  0.250000;0.125000;,
  0.312500;0.000000;,
  0.375000;0.125000;,
  0.437500;0.000000;,
  0.500000;0.125000;,
  0.562500;0.000000;,
  0.625000;0.125000;,
  0.687500;0.000000;,
  0.750000;0.125000;,
  0.812500;0.000000;,
  0.875000;0.125000;,
  0.937500;0.000000;,
  1.000000;0.125000;,
  0.125000;0.250000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  1.000000;0.250000;,
  0.125000;0.375000;,
  0.000000;0.375000;,
  0.250000;0.375000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.750000;0.375000;,
  0.875000;0.375000;,
  1.000000;0.375000;,
  0.125000;0.500000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;,
  0.125000;0.625000;,
  0.000000;0.625000;,
  0.250000;0.625000;,
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.750000;0.625000;,
  0.875000;0.625000;,
  1.000000;0.625000;,
  0.125000;0.750000;,
  0.000000;0.750000;,
  0.250000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.750000;0.750000;,
  0.875000;0.750000;,
  1.000000;0.750000;,
  0.125000;0.875000;,
  0.000000;0.875000;,
  0.250000;0.875000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.750000;0.875000;,
  0.875000;0.875000;,
  1.000000;0.875000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;;
 }
}