#include "users.h"
#include <unistd.h>
#include <pwd.h>

struct passwd * pw;

void load_active_user_c_shell()
{
    __uid_t uid = getuid();
    pw = getpwuid(uid);
}