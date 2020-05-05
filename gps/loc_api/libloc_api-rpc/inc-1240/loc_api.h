/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _LOC_API_H_RPCGEN
#define _LOC_API_H_RPCGEN

#include <rpc/rpc.h>

#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
	u_int rpc_loc_api_api_versions_return_type_len;
	rpc_uint32 *rpc_loc_api_api_versions_return_type_val;
} rpc_loc_api_api_versions_return_type;

typedef rpc_uint32 rpc_loc_event_cb_f_type;

struct rpc_loc_open_args {
	rpc_loc_event_mask_type event_reg_mask;
	rpc_loc_event_cb_f_type event_callback;
};
typedef struct rpc_loc_open_args rpc_loc_open_args;

struct rpc_loc_close_args {
	rpc_loc_client_handle_type handle;
};
typedef struct rpc_loc_close_args rpc_loc_close_args;

struct rpc_loc_start_fix_args {
	rpc_loc_client_handle_type handle;
};
typedef struct rpc_loc_start_fix_args rpc_loc_start_fix_args;

struct rpc_loc_stop_fix_args {
	rpc_loc_client_handle_type handle;
};
typedef struct rpc_loc_stop_fix_args rpc_loc_stop_fix_args;

struct rpc_loc_ioctl_args {
	rpc_loc_client_handle_type handle;
	rpc_loc_ioctl_e_type ioctl_type;
	rpc_loc_ioctl_data_u_type *ioctl_data;
};
typedef struct rpc_loc_ioctl_args rpc_loc_ioctl_args;

struct rpc_loc_api_api_version_s_args {
	rpc_boolean len_not_null;
};
typedef struct rpc_loc_api_api_version_s_args rpc_loc_api_api_version_s_args;

struct rpc_loc_api_rpc_glue_code_info_remote_rets {
	rpc_uint32 toolvers;
	rpc_uint32 features;
	rpc_uint32 proghash;
	rpc_uint32 cbproghash;
};
typedef struct rpc_loc_api_rpc_glue_code_info_remote_rets rpc_loc_api_rpc_glue_code_info_remote_rets;

struct rpc_loc_open_rets {
	rpc_loc_client_handle_type loc_open_result;
};
typedef struct rpc_loc_open_rets rpc_loc_open_rets;

struct rpc_loc_close_rets {
	rpc_int32 loc_close_result;
};
typedef struct rpc_loc_close_rets rpc_loc_close_rets;

struct rpc_loc_start_fix_rets {
	rpc_int32 loc_start_fix_result;
};
typedef struct rpc_loc_start_fix_rets rpc_loc_start_fix_rets;

struct rpc_loc_stop_fix_rets {
	rpc_int32 loc_stop_fix_result;
};
typedef struct rpc_loc_stop_fix_rets rpc_loc_stop_fix_rets;

struct rpc_loc_ioctl_rets {
	rpc_int32 loc_ioctl_result;
};
typedef struct rpc_loc_ioctl_rets rpc_loc_ioctl_rets;

struct rpc_loc_api_api_versions_rets {
	rpc_loc_api_api_versions_return_type loc_api_api_versions_result;
	rpc_uint32 *len;
};
typedef struct rpc_loc_api_api_versions_rets rpc_loc_api_api_versions_rets;
#define LOC_APIVERS 0x00040002

#define LOC_APIPROG 0x3000008c
#define LOC_APIVERS_0001 0x00040001

#if defined(__STDC__) || defined(__cplusplus)
#define rpc_loc_api_null 0
extern  enum clnt_stat rpc_loc_api_null_0x00040001(void *, void *, CLIENT *);
extern  bool_t rpc_loc_api_null_0x00040001_svc(void *, void *, struct svc_req *);
#define rpc_loc_api_rpc_glue_code_info_remote 1
extern  enum clnt_stat rpc_loc_api_rpc_glue_code_info_remote_0x00040001(void *, rpc_loc_api_rpc_glue_code_info_remote_rets *, CLIENT *);
extern  bool_t rpc_loc_api_rpc_glue_code_info_remote_0x00040001_svc(void *, rpc_loc_api_rpc_glue_code_info_remote_rets *, struct svc_req *);
#define rpc_loc_open 2
extern  enum clnt_stat rpc_loc_open_0x00040001(rpc_loc_open_args *, rpc_loc_open_rets *, CLIENT *);
extern  bool_t rpc_loc_open_0x00040001_svc(rpc_loc_open_args *, rpc_loc_open_rets *, struct svc_req *);
#define rpc_loc_close 3
extern  enum clnt_stat rpc_loc_close_0x00040001(rpc_loc_close_args *, rpc_loc_close_rets *, CLIENT *);
extern  bool_t rpc_loc_close_0x00040001_svc(rpc_loc_close_args *, rpc_loc_close_rets *, struct svc_req *);
#define rpc_loc_start_fix 4
extern  enum clnt_stat rpc_loc_start_fix_0x00040001(rpc_loc_start_fix_args *, rpc_loc_start_fix_rets *, CLIENT *);
extern  bool_t rpc_loc_start_fix_0x00040001_svc(rpc_loc_start_fix_args *, rpc_loc_start_fix_rets *, struct svc_req *);
#define rpc_loc_stop_fix 5
extern  enum clnt_stat rpc_loc_stop_fix_0x00040001(rpc_loc_stop_fix_args *, rpc_loc_stop_fix_rets *, CLIENT *);
extern  bool_t rpc_loc_stop_fix_0x00040001_svc(rpc_loc_stop_fix_args *, rpc_loc_stop_fix_rets *, struct svc_req *);
#define rpc_loc_ioctl 6
extern  enum clnt_stat rpc_loc_ioctl_0x00040001(rpc_loc_ioctl_args *, rpc_loc_ioctl_rets *, CLIENT *);
extern  bool_t rpc_loc_ioctl_0x00040001_svc(rpc_loc_ioctl_args *, rpc_loc_ioctl_rets *, struct svc_req *);
#define rpc_loc_api_api_versions 0xFFFFFFFF
extern  enum clnt_stat rpc_loc_api_api_versions_0x00040001(void *, rpc_loc_api_api_versions_rets *, CLIENT *);
extern  bool_t rpc_loc_api_api_versions_0x00040001_svc(void *, rpc_loc_api_api_versions_rets *, struct svc_req *);
extern int loc_apiprog_0x00040001_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define rpc_loc_api_null 0
extern  enum clnt_stat rpc_loc_api_null_0x00040001();
extern  bool_t rpc_loc_api_null_0x00040001_svc();
#define rpc_loc_api_rpc_glue_code_info_remote 1
extern  enum clnt_stat rpc_loc_api_rpc_glue_code_info_remote_0x00040001();
extern  bool_t rpc_loc_api_rpc_glue_code_info_remote_0x00040001_svc();
#define rpc_loc_open 2
extern  enum clnt_stat rpc_loc_open_0x00040001();
extern  bool_t rpc_loc_open_0x00040001_svc();
#define rpc_loc_close 3
extern  enum clnt_stat rpc_loc_close_0x00040001();
extern  bool_t rpc_loc_close_0x00040001_svc();
#define rpc_loc_start_fix 4
extern  enum clnt_stat rpc_loc_start_fix_0x00040001();
extern  bool_t rpc_loc_start_fix_0x00040001_svc();
#define rpc_loc_stop_fix 5
extern  enum clnt_stat rpc_loc_stop_fix_0x00040001();
extern  bool_t rpc_loc_stop_fix_0x00040001_svc();
#define rpc_loc_ioctl 6
extern  enum clnt_stat rpc_loc_ioctl_0x00040001();
extern  bool_t rpc_loc_ioctl_0x00040001_svc();
#define rpc_loc_api_api_versions 0xFFFFFFFF
extern  enum clnt_stat rpc_loc_api_api_versions_0x00040001();
extern  bool_t rpc_loc_api_api_versions_0x00040001_svc();
extern int loc_apiprog_0x00040001_freeresult ();
#endif /* K&R C */
#define LOC_APIVERS_0002 0x00040002

#if defined(__STDC__) || defined(__cplusplus)
extern  enum clnt_stat rpc_loc_api_null_0x00040002(void *, void *, CLIENT *);
extern  bool_t rpc_loc_api_null_0x00040002_svc(void *, void *, struct svc_req *);
extern int loc_apiprog_0x00040002_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
extern  enum clnt_stat rpc_loc_api_null_0x00040002();
extern  bool_t rpc_loc_api_null_0x00040002_svc();
extern int loc_apiprog_0x00040002_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_rpc_loc_api_api_versions_return_type (XDR *, rpc_loc_api_api_versions_return_type*);
extern  bool_t xdr_rpc_loc_event_cb_f_type (XDR *, rpc_loc_event_cb_f_type*);
extern  bool_t xdr_rpc_loc_open_args (XDR *, rpc_loc_open_args*);
extern  bool_t xdr_rpc_loc_close_args (XDR *, rpc_loc_close_args*);
extern  bool_t xdr_rpc_loc_start_fix_args (XDR *, rpc_loc_start_fix_args*);
extern  bool_t xdr_rpc_loc_stop_fix_args (XDR *, rpc_loc_stop_fix_args*);
extern  bool_t xdr_rpc_loc_ioctl_args (XDR *, rpc_loc_ioctl_args*);
extern  bool_t xdr_rpc_loc_api_api_version_s_args (XDR *, rpc_loc_api_api_version_s_args*);
extern  bool_t xdr_rpc_loc_api_rpc_glue_code_info_remote_rets (XDR *, rpc_loc_api_rpc_glue_code_info_remote_rets*);
extern  bool_t xdr_rpc_loc_open_rets (XDR *, rpc_loc_open_rets*);
extern  bool_t xdr_rpc_loc_close_rets (XDR *, rpc_loc_close_rets*);
extern  bool_t xdr_rpc_loc_start_fix_rets (XDR *, rpc_loc_start_fix_rets*);
extern  bool_t xdr_rpc_loc_stop_fix_rets (XDR *, rpc_loc_stop_fix_rets*);
extern  bool_t xdr_rpc_loc_ioctl_rets (XDR *, rpc_loc_ioctl_rets*);
extern  bool_t xdr_rpc_loc_api_api_versions_rets (XDR *, rpc_loc_api_api_versions_rets*);

#else /* K&R C */
extern bool_t xdr_rpc_loc_api_api_versions_return_type ();
extern bool_t xdr_rpc_loc_event_cb_f_type ();
extern bool_t xdr_rpc_loc_open_args ();
extern bool_t xdr_rpc_loc_close_args ();
extern bool_t xdr_rpc_loc_start_fix_args ();
extern bool_t xdr_rpc_loc_stop_fix_args ();
extern bool_t xdr_rpc_loc_ioctl_args ();
extern bool_t xdr_rpc_loc_api_api_version_s_args ();
extern bool_t xdr_rpc_loc_api_rpc_glue_code_info_remote_rets ();
extern bool_t xdr_rpc_loc_open_rets ();
extern bool_t xdr_rpc_loc_close_rets ();
extern bool_t xdr_rpc_loc_start_fix_rets ();
extern bool_t xdr_rpc_loc_stop_fix_rets ();
extern bool_t xdr_rpc_loc_ioctl_rets ();
extern bool_t xdr_rpc_loc_api_api_versions_rets ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_LOC_API_H_RPCGEN */
