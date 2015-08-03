/*******************************************************************************************
 ** TESAnnwyn: A TES3/TES4 height map importer/exporter (to & from RAW or BMP).
 **
 ** Paul Halliday: 31-Dec-2006 
 **
 ** This is entirely my own work. No borrowed code. All reverse engineering has been
 ** researched by myself.
 **
 ** License: GNU (Copy, modify, distribute as you please. ;)
 ***************************************************************************************/

/************************************************************
 ** Common function prototype definition header for TESAnnwyn
 ************************************************************/


// tesannwyn.c

void vhgt_offset_encode(int offset, int *b2, int *b3, int *b4);


// t4d.c: TES4 Decoder & Exporter.
/*
int ExportImages();
int Process4CELLData(char *r, int size);
int Process4LANDData(char *r, int size);
int ExportTES4Land(char *input_esp_filename, char *worldspace, int bpp);
int Process4LTEXData(char *r, int size);
int Process4WRLDData(char *r, int size);
int bytes_to_int(char b1, char b2, char b3, char b4);
int DecompressZLIBStream(char *input, int input_size, char output[], int *output_size);
int CompressZLIBStream(char *input, int input_size, char output[], int *output_size, int compress_level);
int CleanUp();
int WriteBMPHeader(FILE *fp_out, int sx, int sy, int bpp);
int WriteBMPGreyScaleHeader(FILE *fp_out, int sx, int sy, int bpp);
int HumptyImage(char *output_filename, int opt_image_type, int opt_tes_ver, int bpp);
int RescaleGreyScale(char *output_filename, int opt_image_type, int opt_tes_ver, int bpp);
int FixTES3HeaderSize(char *filename, int num_records) ;
int HumptyVCLR(char *output_filename, int opt_tes_ver);
int HumptyVTEX3(char *output_filename, int opt_tes_ver, int layer);
int bytes_to_int(char b1, char b2, char b3, char b4);
*/

// ta-vtex3.c: Process TES3 Texture records
/*
int GetFormIDForFilename(char *tex_filename, char *ltex_name, char *ltex_filename, char *FormID);
void GetVTEX34Cell(unsigned short int vtex[16][16], int ntex[34][34], int cell);
int Match34TexturesQuad(int vtex4[34][34], char *vtex_record, int *vtex_size, int quad);
int GetFormIDFromTEXNum(unsigned short int texnum, char *FormID);
int FormIDToString(char *s, char *formid);
int StringToReverseFormID(char *s, char *formid);
int GetFormIDForFilename(char *tex_filename, char *ltex_name, char *ltex_filename, char *FormID);
int Process3LTEXData(char *r, int size);
int ReadLTEX3(char *filename);
void GetVTEX34Cell(unsigned short int vtex[16][16], int ntex[34][34], int cell) ;
int Match34TexturesQuad(int vtex4[34][34], char *vtex_record, int *vtex_size, int quad);
int GetFormIDFromTEXNum(unsigned short int texnum, char *FormID);
int FormIDToString(char *s, char *formid);
int StringToReverseFormID(char *s, char *formid);
int GetFormIDForFilename(char *tex_filename, char *ltex_name, char *ltex_filename, char *FormID) ;
int Process3LTEXData(char *r, int size);
int ReadLTEX3(char *filename);
*/

// ta-vtex4.c: Process TES4 Texture records
/*
int Process4TEXSubrecords(char *decomp, int size);
int CreateVTEX4Subrecords(int cx, int cy, char vtex4_image[MAX_LAYERS][OB_TEXSIZE][OB_TEXSIZE][3], char *vtex_record);
int ReadVTEX4(char vtex4_image[MAX_LAYERS][OB_TEXSIZE][OB_TEXSIZE][3], int layer, int tex_size, int cx, int cy, int sx, int sy, FILE *fp_vtex);
int ReadLTEX4File();
*/

// lod2.c: Creates LOD2 files (TES4 Oblivion experimental system).

int HumptyLOD2();
int WriteLOD2STAT(FILE *fp, int x, int y);
int WriteLOD2CELL(FILE *fp, int x, int y, int static_formid, int parent_cell_formid);
int WriteTES4RecordHeaderAdvanced(FILE *fp_out, int record, int persist, int depend, char *type);


// nif.c: Generate NIF files (mainly used for LOD2).

void WriteNTSHeader(FILE *fp);
void WriteNTSFooter(FILE *fp);
void WriteNTSBlock(FILE *fp);
int  CreateCellNif(char *nif_filename, char *tex_filename, float height[], float normals[], int dsize);
int  FastInitializeCellNif(int dsize, int res);
int  FastCreateCellNif(char *nif_filename, char *tex_filename, float height[], float normals[], int dsize);
int  CreateNIF(char *heightmap_filename, char *nif_filename, int dimx, int dimy, int x_SW, int y_SW, int res);
FILE *InitializeNIF(char *nif_filename, int dimx, int dimy, int ppr, int rows, int res);
