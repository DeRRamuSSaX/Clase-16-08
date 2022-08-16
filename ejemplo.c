#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char *buffer[] = "";
  char line[250];
  char *filename = argv[1];
  int shift = atoi(argv[2]);
  FILE *fp;
  FILE *temp_file;
  fp = fopen(filename, "r");
  while (fgets(line, 250, fp) != NULL) {
    // strcat(line, '\n');
    // strcpy(buffer,line);
    fprintf(temp_file, "%s", line);
    // printf("%s\n", line);
  }
  fclose(fp);
  fclose(temp_file);
  temp_file = fopen("temp.txt", "r");
  // printf("%s", buffer);
  fp = fopen(filename, 'w');
  while (fgets(line, 250, temp_file) != NULL) {
    //ciframos
    for (int i = 0; i < 250; i++) {

      // if (line[i] != ' ' && line[i] != '\n') {
      //   line[i] = (((line[i] - 'a') + shift) % 26) + 'a';
      //
      // }
    }
    fprintf(temp_file, "%s", line);
    // printf("%s\n", line);
  }
  return 0;
}


#include <stdio.h>
#define MAXLINE 100
//Escribir un programa en C para conectar a la salida de curl -v. El programa tiene que extraer el c ́odigo y mensaje de estado de una respuesta HTTP, como por ejemplo, 200 OK.

int main(void) {
  char buffer[MAXLINE];
  int http_codes[5] = { 200, 201, 307, 404, 500};
  char *http_messages[5] = {
    "OK",
    "Created",
    "Temporary Redirect",
    "Not Found",
    "Internal Server Error"
  };

  while (fgets(buffer, MAXLINE, stdin) != NULL) {
    if (buffer[0] == '<') {
      //printf("%s", buffer);
      char c;
      char protocol[10];
      int code;
      char message[50];
      sscanf(buffer, "< %s %d %s", &c, protocol, &code, message);
      int i = 0;
      while (i < 5){
        if (code == http_codes[i]) {
          break;
        } i++;
      }
      printf("%s %d %s\n", protocol, code, http_messages[i]);
    }
  }
  return 0;
}
