# Round-Robin-and-Priority-Scheduling-xv6
Implementing Round Robin and Priority Scheduling in xv6

Go through the pdf to understand the implementation. 

Remember the default scheduler of xv6 is based on Round Robin algorithm, I did modification in the scheduler() of xv6 and made it capable of Priority    scheduling also.
Priority based Round-Robin CPU Scheduling algorithm is based on the integration of round-robin and priority scheduling algorithm. It retains the advantage of round robin in reducing starvation and also integrates the advantage or priority scheduling.

NOTE :  I have forget to add lyceum.c in the pdf in the Makefile UPROGS. So you do it like this :  under the UPROGS=\ add : _lyceum\
