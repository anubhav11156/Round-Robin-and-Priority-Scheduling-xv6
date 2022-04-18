int
ps()
{
    struct proc *p;
    int d;
    sti();  // some sort of kernerl-user switch gotta happen and it ain't happen without interrupts, so man u gotta enable it....yeah :)
    acquire(&ptable.lock);  // to avoid the race conditionshit boi +_+
    cprintf("NAME \t PID \t PPID \t STATE \t  \t PRIORITY\n");
    // now u have to look in the proc table from the kernel space
    for(p=ptable.proc; p<&ptable.proc[NPROC]; p++)
    {
        if(p->state == SLEEPING)
        {
            d=p->parent->pid;
            if(p->pid == 1)
            {
              d=0;
            }
            cprintf("%s \t %d \t %d \t SLEEPING \t %d \n",p->name,p->pid,d,p->priority);
        }
        else if(p->state == RUNNING)
        {
            d=p->parent->pid;
            if(p->pid == 1)
            {
              d=0;
            }
            cprintf("%s \t %d \t %d \t RUNNING  \t %d \n",p->name,p->pid,d,p->priority);
        }
        else if(p->state == RUNNABLE)
        {
            d=p->parent->pid;
            if(p->pid == 1)
            {
              d=0;
            }
            cprintf("%s \t %d \t %d \t RUNNABLE \t %d \n",p->name,p->pid,d,p->priority);
        }
    }
    release(&ptable.lock);
    return 22;
}
