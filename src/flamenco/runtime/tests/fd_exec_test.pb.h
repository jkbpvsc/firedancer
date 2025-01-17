/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.8-dev */

#ifndef PB_ORG_SOLANA_SEALEVEL_V1_FD_EXEC_TEST_PB_H_INCLUDED
#define PB_ORG_SOLANA_SEALEVEL_V1_FD_EXEC_TEST_PB_H_INCLUDED

#include "../../nanopb/pb_firedancer.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* A set of feature flags. */
typedef struct fd_exec_test_feature_set {
    /* Every item in this list marks an enabled feature.  The value of
 each item is the first 8 bytes of the feature ID as a little-
 endian integer. */
    pb_size_t features_count;
    uint64_t *features;
} fd_exec_test_feature_set_t;

/* The complete state of an account excluding its public key. */
typedef struct fd_exec_test_acct_state {
    /* The account key. Can be ommitted if obvious from the context. */
    bool has_address;
    pb_byte_t address[32];
    uint64_t lamports;
    pb_bytes_array_t *data;
    bool executable;
    uint64_t rent_epoch;
    pb_byte_t owner[32];
} fd_exec_test_acct_state_t;

/* EpochContext includes context scoped to an epoch.
 On "real" ledgers, it is created during the epoch boundary. */
typedef struct fd_exec_test_epoch_context {
    fd_exec_test_feature_set_t features;
} fd_exec_test_epoch_context_t;

/* SlotContext includes context scoped to a block.
 On "real" ledgers, it is created during the slot boundary. */
typedef struct fd_exec_test_slot_context {
    char dummy_field;
} fd_exec_test_slot_context_t;

typedef struct fd_exec_test_txn_context {
    char dummy_field;
} fd_exec_test_txn_context_t;

typedef struct fd_exec_test_instr_acct {
    /* Selects an account in an external list */
    uint32_t index;
    bool is_writable;
    bool is_signer;
} fd_exec_test_instr_acct_t;

/* The execution context of a program invocation (aka instruction).
 Contains all required information to independently replay an instruction.
 Also includes partial transaction context. */
typedef struct fd_exec_test_instr_context {
    /* The address of the program invoked.  (32 bytes) */
    pb_byte_t program_id[32];
    /* The address of the program loader if the invoked program is a user
 deployed program. */
    bool has_loader_id;
    pb_byte_t loader_id[32];
    /* Account state accessed by the instruction. */
    pb_size_t accounts_count;
    struct fd_exec_test_acct_state *accounts;
    /* Account access list for this instruction (refers to above accounts list) */
    pb_size_t instr_accounts_count;
    struct fd_exec_test_instr_acct *instr_accounts;
    /* The input data passed to program execution. */
    pb_bytes_array_t *data;
    uint64_t cu_avail;
    fd_exec_test_txn_context_t txn_context;
    fd_exec_test_slot_context_t slot_context;
    fd_exec_test_epoch_context_t epoch_context;
} fd_exec_test_instr_context_t;

/* The results of executing an InstrContext. */
typedef struct fd_exec_test_instr_effects {
    /* result is zero if the instruction executed succesfully.
 Otherwise, a non-zero error code.  Error codes are implementation
 defined. */
    int32_t result;
    /* Some error cases additionally have a custom error code.  Unlike
 the expected_result, this is stable across clients. */
    bool has_custom_err;
    uint32_t custom_err;
    /* Copies of accounts that were changed.  May be in an arbitrary
 order.  The pubkey of each account is unique in this list.  Each
 account address modified here must also be in the
 InstrContext. */
    pb_size_t modified_accounts_count;
    struct fd_exec_test_acct_state *modified_accounts;
    uint64_t cu_avail;
} fd_exec_test_instr_effects_t;

/* An instruction processing test fixture. */
typedef struct fd_exec_test_instr_fixture {
    fd_exec_test_instr_context_t input;
    fd_exec_test_instr_effects_t output;
} fd_exec_test_instr_fixture_t;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define FD_EXEC_TEST_FEATURE_SET_INIT_DEFAULT    {0, NULL}
#define FD_EXEC_TEST_ACCT_STATE_INIT_DEFAULT     {false, {0}, 0, NULL, 0, 0, {0}}
#define FD_EXEC_TEST_EPOCH_CONTEXT_INIT_DEFAULT  {FD_EXEC_TEST_FEATURE_SET_INIT_DEFAULT}
#define FD_EXEC_TEST_SLOT_CONTEXT_INIT_DEFAULT   {0}
#define FD_EXEC_TEST_TXN_CONTEXT_INIT_DEFAULT    {0}
#define FD_EXEC_TEST_INSTR_ACCT_INIT_DEFAULT     {0, 0, 0}
#define FD_EXEC_TEST_INSTR_CONTEXT_INIT_DEFAULT  {{0}, false, {0}, 0, NULL, 0, NULL, NULL, 0, FD_EXEC_TEST_TXN_CONTEXT_INIT_DEFAULT, FD_EXEC_TEST_SLOT_CONTEXT_INIT_DEFAULT, FD_EXEC_TEST_EPOCH_CONTEXT_INIT_DEFAULT}
#define FD_EXEC_TEST_INSTR_EFFECTS_INIT_DEFAULT  {0, false, 0, 0, NULL, 0}
#define FD_EXEC_TEST_INSTR_FIXTURE_INIT_DEFAULT  {FD_EXEC_TEST_INSTR_CONTEXT_INIT_DEFAULT, FD_EXEC_TEST_INSTR_EFFECTS_INIT_DEFAULT}
#define FD_EXEC_TEST_FEATURE_SET_INIT_ZERO       {0, NULL}
#define FD_EXEC_TEST_ACCT_STATE_INIT_ZERO        {false, {0}, 0, NULL, 0, 0, {0}}
#define FD_EXEC_TEST_EPOCH_CONTEXT_INIT_ZERO     {FD_EXEC_TEST_FEATURE_SET_INIT_ZERO}
#define FD_EXEC_TEST_SLOT_CONTEXT_INIT_ZERO      {0}
#define FD_EXEC_TEST_TXN_CONTEXT_INIT_ZERO       {0}
#define FD_EXEC_TEST_INSTR_ACCT_INIT_ZERO        {0, 0, 0}
#define FD_EXEC_TEST_INSTR_CONTEXT_INIT_ZERO     {{0}, false, {0}, 0, NULL, 0, NULL, NULL, 0, FD_EXEC_TEST_TXN_CONTEXT_INIT_ZERO, FD_EXEC_TEST_SLOT_CONTEXT_INIT_ZERO, FD_EXEC_TEST_EPOCH_CONTEXT_INIT_ZERO}
#define FD_EXEC_TEST_INSTR_EFFECTS_INIT_ZERO     {0, false, 0, 0, NULL, 0}
#define FD_EXEC_TEST_INSTR_FIXTURE_INIT_ZERO     {FD_EXEC_TEST_INSTR_CONTEXT_INIT_ZERO, FD_EXEC_TEST_INSTR_EFFECTS_INIT_ZERO}

/* Field tags (for use in manual encoding/decoding) */
#define FD_EXEC_TEST_FEATURE_SET_FEATURES_TAG    1
#define FD_EXEC_TEST_ACCT_STATE_ADDRESS_TAG      1
#define FD_EXEC_TEST_ACCT_STATE_LAMPORTS_TAG     2
#define FD_EXEC_TEST_ACCT_STATE_DATA_TAG         3
#define FD_EXEC_TEST_ACCT_STATE_EXECUTABLE_TAG   4
#define FD_EXEC_TEST_ACCT_STATE_RENT_EPOCH_TAG   5
#define FD_EXEC_TEST_ACCT_STATE_OWNER_TAG        6
#define FD_EXEC_TEST_EPOCH_CONTEXT_FEATURES_TAG  1
#define FD_EXEC_TEST_INSTR_ACCT_INDEX_TAG        1
#define FD_EXEC_TEST_INSTR_ACCT_IS_WRITABLE_TAG  2
#define FD_EXEC_TEST_INSTR_ACCT_IS_SIGNER_TAG    3
#define FD_EXEC_TEST_INSTR_CONTEXT_PROGRAM_ID_TAG 1
#define FD_EXEC_TEST_INSTR_CONTEXT_LOADER_ID_TAG 2
#define FD_EXEC_TEST_INSTR_CONTEXT_ACCOUNTS_TAG  3
#define FD_EXEC_TEST_INSTR_CONTEXT_INSTR_ACCOUNTS_TAG 4
#define FD_EXEC_TEST_INSTR_CONTEXT_DATA_TAG      5
#define FD_EXEC_TEST_INSTR_CONTEXT_CU_AVAIL_TAG  6
#define FD_EXEC_TEST_INSTR_CONTEXT_TXN_CONTEXT_TAG 7
#define FD_EXEC_TEST_INSTR_CONTEXT_SLOT_CONTEXT_TAG 8
#define FD_EXEC_TEST_INSTR_CONTEXT_EPOCH_CONTEXT_TAG 9
#define FD_EXEC_TEST_INSTR_EFFECTS_RESULT_TAG    1
#define FD_EXEC_TEST_INSTR_EFFECTS_CUSTOM_ERR_TAG 2
#define FD_EXEC_TEST_INSTR_EFFECTS_MODIFIED_ACCOUNTS_TAG 3
#define FD_EXEC_TEST_INSTR_EFFECTS_CU_AVAIL_TAG  4
#define FD_EXEC_TEST_INSTR_FIXTURE_INPUT_TAG     1
#define FD_EXEC_TEST_INSTR_FIXTURE_OUTPUT_TAG    2

/* Struct field encoding specification for nanopb */
#define FD_EXEC_TEST_FEATURE_SET_FIELDLIST(X, a) \
X(a, POINTER,  REPEATED, FIXED64,  features,          1)
#define FD_EXEC_TEST_FEATURE_SET_CALLBACK NULL
#define FD_EXEC_TEST_FEATURE_SET_DEFAULT NULL

#define FD_EXEC_TEST_ACCT_STATE_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, FIXED_LENGTH_BYTES, address,           1) \
X(a, STATIC,   REQUIRED, UINT64,   lamports,          2) \
X(a, POINTER,  REQUIRED, BYTES,    data,              3) \
X(a, STATIC,   REQUIRED, BOOL,     executable,        4) \
X(a, STATIC,   REQUIRED, UINT64,   rent_epoch,        5) \
X(a, STATIC,   REQUIRED, FIXED_LENGTH_BYTES, owner,             6)
#define FD_EXEC_TEST_ACCT_STATE_CALLBACK NULL
#define FD_EXEC_TEST_ACCT_STATE_DEFAULT NULL

#define FD_EXEC_TEST_EPOCH_CONTEXT_FIELDLIST(X, a) \
X(a, STATIC,   REQUIRED, MESSAGE,  features,          1)
#define FD_EXEC_TEST_EPOCH_CONTEXT_CALLBACK NULL
#define FD_EXEC_TEST_EPOCH_CONTEXT_DEFAULT NULL
#define fd_exec_test_epoch_context_t_features_MSGTYPE fd_exec_test_feature_set_t

#define FD_EXEC_TEST_SLOT_CONTEXT_FIELDLIST(X, a) \

#define FD_EXEC_TEST_SLOT_CONTEXT_CALLBACK NULL
#define FD_EXEC_TEST_SLOT_CONTEXT_DEFAULT NULL

#define FD_EXEC_TEST_TXN_CONTEXT_FIELDLIST(X, a) \

#define FD_EXEC_TEST_TXN_CONTEXT_CALLBACK NULL
#define FD_EXEC_TEST_TXN_CONTEXT_DEFAULT NULL

#define FD_EXEC_TEST_INSTR_ACCT_FIELDLIST(X, a) \
X(a, STATIC,   REQUIRED, UINT32,   index,             1) \
X(a, STATIC,   REQUIRED, BOOL,     is_writable,       2) \
X(a, STATIC,   REQUIRED, BOOL,     is_signer,         3)
#define FD_EXEC_TEST_INSTR_ACCT_CALLBACK NULL
#define FD_EXEC_TEST_INSTR_ACCT_DEFAULT NULL

#define FD_EXEC_TEST_INSTR_CONTEXT_FIELDLIST(X, a) \
X(a, STATIC,   REQUIRED, FIXED_LENGTH_BYTES, program_id,        1) \
X(a, STATIC,   OPTIONAL, FIXED_LENGTH_BYTES, loader_id,         2) \
X(a, POINTER,  REPEATED, MESSAGE,  accounts,          3) \
X(a, POINTER,  REPEATED, MESSAGE,  instr_accounts,    4) \
X(a, POINTER,  REQUIRED, BYTES,    data,              5) \
X(a, STATIC,   REQUIRED, UINT64,   cu_avail,          6) \
X(a, STATIC,   REQUIRED, MESSAGE,  txn_context,       7) \
X(a, STATIC,   REQUIRED, MESSAGE,  slot_context,      8) \
X(a, STATIC,   REQUIRED, MESSAGE,  epoch_context,     9)
#define FD_EXEC_TEST_INSTR_CONTEXT_CALLBACK NULL
#define FD_EXEC_TEST_INSTR_CONTEXT_DEFAULT NULL
#define fd_exec_test_instr_context_t_accounts_MSGTYPE fd_exec_test_acct_state_t
#define fd_exec_test_instr_context_t_instr_accounts_MSGTYPE fd_exec_test_instr_acct_t
#define fd_exec_test_instr_context_t_txn_context_MSGTYPE fd_exec_test_txn_context_t
#define fd_exec_test_instr_context_t_slot_context_MSGTYPE fd_exec_test_slot_context_t
#define fd_exec_test_instr_context_t_epoch_context_MSGTYPE fd_exec_test_epoch_context_t

#define FD_EXEC_TEST_INSTR_EFFECTS_FIELDLIST(X, a) \
X(a, STATIC,   REQUIRED, INT32,    result,            1) \
X(a, STATIC,   OPTIONAL, UINT32,   custom_err,        2) \
X(a, POINTER,  REPEATED, MESSAGE,  modified_accounts,   3) \
X(a, STATIC,   REQUIRED, UINT64,   cu_avail,          4)
#define FD_EXEC_TEST_INSTR_EFFECTS_CALLBACK NULL
#define FD_EXEC_TEST_INSTR_EFFECTS_DEFAULT NULL
#define fd_exec_test_instr_effects_t_modified_accounts_MSGTYPE fd_exec_test_acct_state_t

#define FD_EXEC_TEST_INSTR_FIXTURE_FIELDLIST(X, a) \
X(a, STATIC,   REQUIRED, MESSAGE,  input,             1) \
X(a, STATIC,   REQUIRED, MESSAGE,  output,            2)
#define FD_EXEC_TEST_INSTR_FIXTURE_CALLBACK NULL
#define FD_EXEC_TEST_INSTR_FIXTURE_DEFAULT NULL
#define fd_exec_test_instr_fixture_t_input_MSGTYPE fd_exec_test_instr_context_t
#define fd_exec_test_instr_fixture_t_output_MSGTYPE fd_exec_test_instr_effects_t

extern const pb_msgdesc_t fd_exec_test_feature_set_t_msg;
extern const pb_msgdesc_t fd_exec_test_acct_state_t_msg;
extern const pb_msgdesc_t fd_exec_test_epoch_context_t_msg;
extern const pb_msgdesc_t fd_exec_test_slot_context_t_msg;
extern const pb_msgdesc_t fd_exec_test_txn_context_t_msg;
extern const pb_msgdesc_t fd_exec_test_instr_acct_t_msg;
extern const pb_msgdesc_t fd_exec_test_instr_context_t_msg;
extern const pb_msgdesc_t fd_exec_test_instr_effects_t_msg;
extern const pb_msgdesc_t fd_exec_test_instr_fixture_t_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define FD_EXEC_TEST_FEATURE_SET_FIELDS &fd_exec_test_feature_set_t_msg
#define FD_EXEC_TEST_ACCT_STATE_FIELDS &fd_exec_test_acct_state_t_msg
#define FD_EXEC_TEST_EPOCH_CONTEXT_FIELDS &fd_exec_test_epoch_context_t_msg
#define FD_EXEC_TEST_SLOT_CONTEXT_FIELDS &fd_exec_test_slot_context_t_msg
#define FD_EXEC_TEST_TXN_CONTEXT_FIELDS &fd_exec_test_txn_context_t_msg
#define FD_EXEC_TEST_INSTR_ACCT_FIELDS &fd_exec_test_instr_acct_t_msg
#define FD_EXEC_TEST_INSTR_CONTEXT_FIELDS &fd_exec_test_instr_context_t_msg
#define FD_EXEC_TEST_INSTR_EFFECTS_FIELDS &fd_exec_test_instr_effects_t_msg
#define FD_EXEC_TEST_INSTR_FIXTURE_FIELDS &fd_exec_test_instr_fixture_t_msg

/* Maximum encoded size of messages (where known) */
/* fd_exec_test_FeatureSet_size depends on runtime parameters */
/* fd_exec_test_AcctState_size depends on runtime parameters */
/* fd_exec_test_EpochContext_size depends on runtime parameters */
/* fd_exec_test_InstrContext_size depends on runtime parameters */
/* fd_exec_test_InstrEffects_size depends on runtime parameters */
/* fd_exec_test_InstrFixture_size depends on runtime parameters */
#define FD_EXEC_TEST_INSTR_ACCT_SIZE             10
#define FD_EXEC_TEST_SLOT_CONTEXT_SIZE           0
#define FD_EXEC_TEST_TXN_CONTEXT_SIZE            0

/* Mapping from canonical names (mangle_names or overridden package name) */
#define org_solana_sealevel_v1_FeatureSet fd_exec_test_FeatureSet
#define org_solana_sealevel_v1_AcctState fd_exec_test_AcctState
#define org_solana_sealevel_v1_EpochContext fd_exec_test_EpochContext
#define org_solana_sealevel_v1_SlotContext fd_exec_test_SlotContext
#define org_solana_sealevel_v1_TxnContext fd_exec_test_TxnContext
#define org_solana_sealevel_v1_InstrAcct fd_exec_test_InstrAcct
#define org_solana_sealevel_v1_InstrContext fd_exec_test_InstrContext
#define org_solana_sealevel_v1_InstrEffects fd_exec_test_InstrEffects
#define org_solana_sealevel_v1_InstrFixture fd_exec_test_InstrFixture

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
