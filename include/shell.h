#ifndef SHELL_H

/**
 * @brief The following thread, handles incoming text from
 * the user and executes particular commands.
 * @param param
 * @return void
 */
void* shell_mngr(void * th_id);

#endif //SHELL_H