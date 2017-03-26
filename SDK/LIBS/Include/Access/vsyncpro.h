/******************************************************************************
 *
 * vsyncpro.c - V-SYNC割込み処理の宣言
 *
 * -- 著作権表示 --
 *
 *  Copyright(C) 1997 by ACCESS Co.,Ltd.
 *  All right reseved.
 *
 * -- 変更記録 --
 *
 *  $Log: /NetFront/TCP/dm_sdk/dmcast/vsyncpro.h $
 * 
 * 1     98/10/26 14:53 Ueda
 * make branch dream-cast SDK
 * 
 * 1     98/08/19 18:33 Kawaguti
 *
 *****************************************************************************/
#ifdef __cplusplus /* Support for C++ */
extern "C" {
#endif /* __cplusplus */

#if !defined(VSYNCPRO_H)
#define VSYNCPRO_H

/*
 * 各種ヘッダの引用セクション
 */

/* 忍ライブラリのインクルードファイルを取り込む */
#include <shinobi.h>

/*
 * 外部公開する関数の宣言セクション
 */

/******************************************************************************
 * vsInitVSyncProc - V-SYNC処理の初期化
 *****************************************************************************/

extern void
vsInitVSyncProc(void *callback);

/******************************************************************************
 * vsFinishVSyncProc - V-SYNC処理の終了
 *****************************************************************************/

extern void
vsFinishVSyncProc();

/******************************************************************************
 * vsWaitVSync - n回のV-SYNCを待つ
 *****************************************************************************/

extern void
vsWaitVSync(int n);

/******************************************************************************
 * vsStartPppDaemon - PPPデーモンの開始
 *****************************************************************************/

extern void
vsStartPppDaemon(void);

/******************************************************************************
 * vsStopPppDaemon - PPPデーモンの停止
 *****************************************************************************/

extern void
vsStopPppDaemon(void);

/******************************************************************************
 * vsStartTcpipDaemon - TCP/IPデーモンの開始
 *****************************************************************************/

extern void
vsStartTcpipDaemon(void);

/******************************************************************************
 * vsStopTcpipDaemon - TCP/IPデーモンの停止
 *****************************************************************************/

extern void
vsStopTcpipDaemon(void);

/******************************************************************************
 * vsEnterCriticalSection - クリティカルセクションに入る
 *****************************************************************************/

extern int
vsEnterCriticalSection(void);

/******************************************************************************
 * vsLeaveCriticalSection - クリティカルセクションを出る
 *****************************************************************************/

extern void
vsLeaveCriticalSection(int savedLevel);

/******************************************************************************
 * vsPausePppDaemon - PPPデーモンを停止する
 *****************************************************************************/

extern void
vsPausePppDaemon(void);

/******************************************************************************
 * vsPauseTcpipDaemon - TCP/IPデーモンを停止する
 *****************************************************************************/

extern void
vsPauseTcpipDaemon(void);

/******************************************************************************
 * vsGetTickCount - V割込みの回数を返す
 *****************************************************************************/

extern int
vsGetTickCount(void);

#endif /* !defined(VSYNCPRO_H) */

#ifdef __cplusplus
} /* End of extern "C" { */
#endif /* __cplusplus */
/*****************************************************************************/
/* Muleの設定(必ず各行が1行コメントでなければ認識されないので注意) */
/* Local Variables: */
/* mode: c */
/* tab-width: 4 */
/*****************************************************************************/
