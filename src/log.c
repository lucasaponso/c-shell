#include <syslog.h>
#include "log.h"

#define SYSLOG_C_SHELL "c-shell"

void c_shell_init_syslog()
{
    openlog(SYSLOG_C_SHELL, LOG_PID | LOG_CONS, LOG_USER);
    c_shell_log("Syslog connection successful, forwarding to syslog", C_SHELL_LOG_INFO);
}

void c_shell_close_syslog()
{
    c_shell_log("Closing Syslog, connection severed.", C_SHELL_LOG_NOTICE);
    closelog();
}

void c_shell_log(const char * msg, c_shell_syslog_info_type log_type)
{
    syslog(log_type, msg);
}