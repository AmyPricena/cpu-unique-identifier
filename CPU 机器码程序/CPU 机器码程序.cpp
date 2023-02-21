#include <iostream>
#include <Windows.h>

using namespace std;

int main() {   
    // 定义变量
    DWORD dwSize = 0;
    LPBYTE lpBuffer = NULL;
    BOOL bSuccess = FALSE;

    // 获取缓冲区大小
    bSuccess = GetSystemFirmwareTable('RSMB', 0, NULL, dwSize);
    if (!bSuccess) {
        cout << "获取缓冲区大小失败！" << endl;
        return 1;
    }

    // 分配缓冲区
    lpBuffer = new BYTE[dwSize];
    if (lpBuffer == NULL) {
        cout << "分配缓冲区失败！" << endl;
        return 1;
    }

    // 获取CPU唯一识别码
    bSuccess = GetSystemFirmwareTable('RSMB', 0, lpBuffer, dwSize);
    if (!bSuccess) {
        cout << "获取CPU唯一识别码失败！" << endl;
        delete[] lpBuffer;
        return 1;
    }

    // 输出CPU唯一识别码
    cout << "CPU唯一识别码：";
    for (DWORD i = 8; i < dwSize; i++) {
        printf("%02X", lpBuffer[i]);
    }
    cout << endl;

    // 释放缓冲区
    delete[] lpBuffer;

    return 0;
}
