#ifndef HEADER_fd_src_flamenco_runtime_context_fd_exec_instr_ctx_h
#define HEADER_fd_src_flamenco_runtime_context_fd_exec_instr_ctx_h

#include "../fd_runtime.h"
#include "../info/fd_instr_info.h"

/* fd_exec_instr_ctx_t is the context needed to execute a single
   instruction (program invocation). */

struct __attribute__((aligned(8UL))) fd_exec_instr_ctx {
  ulong magic; /* ==FD_EXEC_INSTR_CTX_MAGIC */

  fd_exec_epoch_ctx_t const * epoch_ctx;
  fd_exec_slot_ctx_t *        slot_ctx; /* TODO: needs to be made const to be thread safe. */
  fd_exec_txn_ctx_t *         txn_ctx;  /* The transaction context for this instruction */

  fd_funk_txn_t * funk_txn;
  fd_acc_mgr_t *  acc_mgr;
  fd_valloc_t     valloc;

  fd_instr_info_t const *     instr;
};

#define FD_EXEC_INSTR_CTX_ALIGN     (alignof(fd_exec_instr_ctx_t))
#define FD_EXEC_INSTR_CTX_FOOTPRINT (sizeof (fd_exec_instr_ctx_t))
#define FD_EXEC_INSTR_CTX_MAGIC (0x18964FC6EDAAC5A8UL) /* random */

FD_PROTOTYPES_BEGIN

/* Constructors */

void *
fd_exec_instr_ctx_new( void * mem );

fd_exec_instr_ctx_t *
fd_exec_instr_ctx_join( void * mem );

void *
fd_exec_instr_ctx_leave( fd_exec_instr_ctx_t * ctx );

void *
fd_exec_instr_ctx_delete( void * mem );

/* Helpers for borrowing instruction accounts */

int
fd_instr_borrowed_account_view_idx( fd_exec_instr_ctx_t *    ctx,
                                    uchar                    idx,
                                    fd_borrowed_account_t ** account );
int
fd_instr_borrowed_account_view( fd_exec_instr_ctx_t *    ctx,
                                fd_pubkey_t const *      pubkey,
                                fd_borrowed_account_t ** account );
int
fd_instr_borrowed_account_modify_idx( fd_exec_instr_ctx_t *    ctx,
                                      uchar                    idx,
                                      ulong                    min_data_sz,
                                      fd_borrowed_account_t ** account );
int
fd_instr_borrowed_account_modify( fd_exec_instr_ctx_t *    ctx,
                                  fd_pubkey_t const *      pubkey,
                                  ulong                    min_data_sz,
                                  fd_borrowed_account_t ** account );

FD_PROTOTYPES_END

#endif /* HEADER_fd_src_flamenco_runtime_context_fd_exec_instr_ctx_h */
