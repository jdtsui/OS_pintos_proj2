#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"


static void syscall_handler (struct intr_frame *);

typedef void(*CALL_PROC)(struct intr_frame *);

CALL_PROC pfn[MAXCALL];

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
  int i;
  for (i=0; i < MAXCALL; i++){
  	pfn[i] = NULL;
  }
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
	if (!is_user_vaddr(f->esp)){
		ExitStatus(-1);
	}
	int No = *((int*)(f->esp));
	if (No>MAXCALL || MAXCALL<0){
		ExitStatus(-1);
	}
	if (pfn[No]==NULL){
		ExitStatus(-1);
	}
	pfn[No](f);

}
