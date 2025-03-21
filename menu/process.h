#ifndef PROCESS_H
#define PROCESS_H

#include "base.h"

MenuItem* Method::get_process_ptr(){
    MenuItem* process_ptr = new MenuItem;
    process_ptr->name = "process";
    process_ptr->submenu = {
        {"process +", {
            {"ps +", {{"show all process#ps aux#"},
                      {"show all process with their executable binary paths#ps -ef#"},
                      {"show all process info of certain user#ps -u ${userid}#"},
                      {"show info of certain process by pid#ps --pid ${pid}#"},
                      {"show desired info of certain process by pid# ps -o pid,comm,user,state,rss --pid ${pid}#"},
                      {"show parent proc id (ppid) of given pid#ps j ${pid}#"},
                      {"show full cmdline for a proc#ps -ef | grep ${pid} | awk '{ for(i=${col}; i<=NF; i++) printf \"%s \", $i; print \"\" }'#"}}},
            {"pstree +", {{"show parent graph tree of cur proc recusively in decimal format#pstree -s -p ${pid}#"}}},
            {"cpu affinity +", {{"get certain proc's cpu affinity#taskset#"}}},
            {"procfs +", {{"show the cmdline that start the process#cat /proc/${pid}/cmdline#"},
                          {"show the status of a process (todo: explanation needed)#cat /proc/${pid}/status#"}}},
            {"kill +", {{"kill +", {{"stop execution of certain process#kill -SIGSTOP ${pid}#"},
                                    {"continue execution of certain process#kill -SIGCONT ${pid}#"}}},
                        {"pkill +", {{"kill all processes with name exactly match the pattern#pkill -f ${pattern}#"}}}}},
            {"ipc +", {{"ipcs +", {{"show info on ipc facilities (only systemv)#man ipcs#"},
                                   {"show share memory segment info#ipcs -m#"}}}}},
            {"capabilities +", {{"show manual of linux capabilities#man capabilities#"},
                                {"setcap +"},
                                {"getcap +"}}}},
        },
    };
    return process_ptr;
}

#endif
