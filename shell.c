
#include "header.h"
#define BUFSIZE 1024
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

// ----- llamado de funcion LO QUE DILAN QUERIA-----------
char *array_str[] = {
  "clr",
  "cd",
  "ls",
  "echo",
  "pause",
  "quit"
 
};

// ----- array de funciones (DISPARADORES) -----------
int (*array_funciones[]) (char **) = {
  &funcion_clear,
  &funcion_cd,
  &funcion_ls,
  &funcion_echo,
  &funcion_pause,
  &funcion_exit
 
};

int longitud_array_bit() {
  return sizeof(array_str) / sizeof(char *);
}

/**
 * verificar si el argumento que entra es un directorio existente 
 * también si no envía ningun argumento lo solicitamos
 * BUG: SE IMPRIME 2 VECES LA MIERDA ESTA de PWD
 */
int funcion_cd(char **args)
{
  //pregunta si el argumento es diferente de null o vacio
  if (args[1] != NULL && args[1] != "") {
    if (chdir(args[1]) != 0){ 
      printf("error xd: el triplemalpario directorio <%s> no existe caregueva\n",args[1]);   
    }
  } else {
      printf("de un malparido argumento \"cd\"\n");
  }
  system("pwd");
  return 1;
}



/**
 * Funcion pa salir
 */
int funcion_exit(char **args)
{
  return 0;
}

/**
 * Función para limpiar la consola
 */
 int funcion_clear(char **args)
{

    system("clear");
  
  return 1;
} 
/**
 * Función listar el directorio
 */
int funcion_ls(char **args)
{
  system("ls");
  return 1;
} 
/**
 * Función comentario
 */
int funcion_echo(char **args)
{
  if (args[1] == NULL || args[1] == "") {
     printf("falta argumento maricon\n");
  }else{
      printf("%s\n",args[1]);
  }
  return 1;
} 

/**
 * Función pause
 */
int funcion_pause(char **args)
{
  system("exit");
  return 1;
} 

 
 

/**
 * iniciar un disparador y esperar que termine 
 */
int hilos_programa(char **args)
{
  //Declaramos el PID y su estado
  pid_t pid;
  int estado;
  //iniciamos el fork
  pid = fork(); 
  if (pid < 0) { 
    printf("error xd\n");
  } else if (pid == 0) {
    if (execvp(args[0], args) == -1) printf("error xd comando no existe ESPERANZA METASE EL DEDO\n");
    exit(EXIT_FAILURE);
  } else {
    //proceso ejecutando
    do {
      waitpid(pid, &estado, WUNTRACED);
    } while (!WIFEXITED(estado) && !WIFSIGNALED(estado));
  }
  return 1;
}

/**
 *  Verificamos si los comandos son iguales a los que tenemos si es así corralo
 */
int comando(char **args)
{
  int i;
  if (args[0] == NULL) return 1;
  for (i = 0; i < longitud_array_bit(); i++) {
    if (strcmp(args[0], array_str[i]) == 0) {
      return (*array_funciones[i])(args);
    }
  }
  return hilos_programa(args);
}


/**
 * se lee la linea de comando
 */
char *lectura(void)
{
  int bufsize = BUFSIZE;
  int posicion = 0;
  int var;
  char *buffer = malloc(sizeof(char) * bufsize);
  if (!buffer) {
    printf("error xd\n");
    exit(EXIT_FAILURE); 
  }
  while (1) {
    var = getchar(); //cadena de caracteres
    if (var == '\n') {
      buffer[posicion] = '\0';
      return buffer;
    }else if (var == EOF) {
      exit(EXIT_SUCCESS);
    } else {
      buffer[posicion] = var;
    }
    posicion++;
    if (posicion >= bufsize) {
      bufsize += BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        printf("error xd\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}


/**
 * Separa la cadena de comando en un programa y argumentos.
 */
char **split_linea(char *line)
{
  int bufsize = TOK_BUFSIZE, posicion = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token, **tokens_backup;
  if (!tokens) {
    printf("error xd\n");
    exit(EXIT_FAILURE);
  }
  token = strtok(line, TOK_DELIM);
  while (token != NULL) {
    tokens[posicion] = token;
    posicion++;
    if (posicion >= bufsize) {
      bufsize += TOK_BUFSIZE;
      tokens_backup = tokens;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
		free(tokens_backup);
        printf("error xd\n");
        exit(EXIT_FAILURE);
      }
    }
    token = strtok(NULL, TOK_DELIM);
  }
  tokens[posicion] = NULL;
  return tokens;
}

int main(int argc, char **argv)
{

    char *linea;
    char **args;
    int estado;
    do {
      printf("PERICO.EXE~$ ",system("pwd"));
      if(argv[1] != NULL){
        linea = argv[1];
      }else{
        linea = lectura();
      }
      args = split_linea(linea);
      estado = comando(args);
      free(linea);
      free(args);
    } while (estado);
    return EXIT_SUCCESS;
 
}
