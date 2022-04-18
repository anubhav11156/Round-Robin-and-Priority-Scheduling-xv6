void
scheduler(void)
{
  struct proc *p;
  struct proc *p1;
  struct cpu *c = mycpu();
  c->proc = 0;

  for(;;){
    // Enable interrupts on this processor.
    sti(); // some sort of kernel-user switch gotta happen so u will have to enable this interrupt.

    struct proc *high_p; // this for getting the process whose priority I will change
    // Loop over process table looking for process to run.
    acquire(&ptable.lock); // to avoid the race condition
    for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){ // looping over the process table
      if(p->state != RUNNABLE)
        continue;

      high_p = p;
      // now choosing one with highest priority
      for(p1=ptable.proc; p1 < &ptable.proc[NPROC]; p1++ ){
          if(p1->state != RUNNABLE)
              continue;
          if(high_p->priority > p1->priority)
              high_p = p1;
      }
      p = high_p;
      // Switch to chosen process.  It is the process's job
      // to release ptable.lock and then reacquire it
      // before jumping back to us.
      c->proc = p;
      switchuvm(p);
      p->state = RUNNING;
      swtch(&(c->scheduler), p->context);
      switchkvm();
      // Process is done running for now.
      // It should have changed its p->state before coming back.
      c->proc = 0;
    }
    release(&ptable.lock);
  }
}
