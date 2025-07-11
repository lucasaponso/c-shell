#ifndef USERS_H
#define USERS_H

#include <pwd.h>

/**
 * @brief The following function retrieves the current
 * user information into a structure by using the UID C API.
 */
void load_active_user_c_shell();

/**
 * @brief Structure representing active user
 */
extern struct passwd * pw;

#endif //USERS_H