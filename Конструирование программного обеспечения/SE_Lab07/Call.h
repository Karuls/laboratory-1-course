
namespace Call {

int _cdecl ñdecl(int x, int y, int z);
int _stdcall stdcall(int& x, int y, int z);
int _fastcall fastcall(int x, int y, int z, int w);

int ñdecl(int x, int y, int z) {
    return x + y + z;
}

int  _stdcall stdcall(int& x, int y, int z) {
    return x * y * z;
}

int  _fastcall fastcall(int x, int y, int z, int w) {
    return x + y + z + w;
}

}