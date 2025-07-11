#ifndef LOG_H
#define LOG_H

/**
 * @brief The following enum refers to info 
 * priorities for syslog.
 */
typedef enum
{
    C_SHELL_LOG_EMERG,
    C_SHELL_LOG_ALERT,
    C_SHELL_LOG_CRIT,
    C_SHELL_LOG_ERR,
    C_SHELL_LOG_WARNING,
    C_SHELL_LOG_NOTICE,
    C_SHELL_LOG_INFO,
    C_SHELL_LOG_DEBUG
} c_shell_syslog_info_type;

/**
 * @brief The following function init, the 
 * syslog service
 */
void c_shell_init_syslog();

/**
 * @brief The following function closes
 * the syslog service
 */
void c_shell_close_syslog();

void c_shell_log(const char * msg, c_shell_syslog_info_type log_type);

#endif //LOG_H