#include <stdio.h>

int main() {
    FILE * fp = fopen("/out", "w");
    
    unsigned char syscall[8] = {0x39,0x05,0,0,0,0,0,0};
    unsigned char junk[48] = {0};

    fwrite(syscall, 1, 8, fp);
    fwrite(junk, 1, 48, fp);
    fwrite("PleaseSu", 1, 8, fp);

/*    fwrite(syscall, 1, 8, fp);
    fwrite(junk, 1, 48, fp);
    fwrite("bscribe!", 1, 8, fp);
  */  
    rename("/out", "/log");
}
