# This requires a patched version of radare2 to remove the forced base address that is used:
# diff --git a/libr/bin/format/pe/pe.c b/libr/bin/format/pe/pe.c
# index 2f0f786eb..0c5343fd3 100644
# --- a/libr/bin/format/pe/pe.c
# +++ b/libr/bin/format/pe/pe.c
# @@ -331,7 +331,4 @@ ut64 PE_(r_bin_pe_get_image_base)(struct PE_(r_bin_pe_obj_t)* bin) {
#                 imageBase = 0x10000;
#         }
# -       if (imageBase < bin->size) {
# -               imageBase = 0x8000000;
# -       }
#         return imageBase;
#  }

f sym.memcpy 829 0x00ae8090
af+ 0x00ae8090 sym.memcpy f n
afu 0x00ae83cd @ 0x00ae8090

f sym.strcpy 248 0x00aeb8e0
af+ 0x00aeb8e0 sym.strcpy f n
afu 0x00aeb9d8 @ 0x00aeb8e0

afr sym.jmp.KERNEL32.dll_RtlUnwind 0x00b318f2
afr sym.jmp.DINPUT8.dll_DirectInput8Create 0x00af1200
afr sym.jmp.d3d9.dll_Direct3DCreate9 0x00af12c0
afr sym.jmp.DSOUND.dll_DirectSoundCreate8 0x00af12c6
afr sym.jmp.KERNEL32.dll_GetCurrentProcessId 0x00b35800

afr sym.__sbh_memcpy @ 0x00ae39e0
afr sym.memset 0x00ae49e0

afr sym.__sbh_free_block.00ae3ac0 0x00ae3ac0
afr sym.__sbh_free_block.00ae3c78 0x00ae3c78

afr sym.__sbh_alloc_block 0x00ae7869
afr sym.__sbh_alloc_new_group 0x00ae7484
afr sym.__sbh_alloc_new_region 0x00ae73cd
afr sym.__sbh_find_block 0x00ae708a
afr sym.__sbh_free_block 0x00ae70b5
afr sym.__sbh_heap_init 0x00ae7042
afr sym.__sbh_resize_block 0x00ae758a

afr sym._SEH_prolog 0x00ae65bc
afr sym._SEH_epilog 0x00ae65f7

afr sym.strcmp 0x00aec9d0

afr sym.strncmp 0x00ae3090
afvb 0x08 str1 const char * @ 0x00ae3090
afvb 0x0c str2 const char * @ 0x00ae3090
afvb 0x10 num size_t @ 0x00ae3090

afr sym.strlen 0x00ae5b10
afr sym.strchr 0x00ae4c20
afr sym.strrchr 0x00b36820
afr sym.strspn 0x00b34bb0
afr sym.strcspn 0x00b34190
afr sym.strncpy 0x00aeb9e0
afr sym.strncnt 0x00aeefb8

afr sym._heap_alloc 0x00ae35c2
afr sym._callnewh 0x00ae7b65
afr sym._nh_malloc 0x00ae3608
afr sym._alloca_probe 0x00ae6610
afr sym.malloc 0x00ae3634
afr sym.calloc 0x00aeccf1
afr sym.free 0x00ae3646
afr sym.realloc 0x00aec01c

afr sym._NLG_Notify 0x00aee57e
afr sym._global_unwind2 0x00aee4a8
afr sym._local_unwind2 0x00aee4ea
afr sym._unwind_handler 0x00aee4c8
afr sym._except_handler3 0x00aebf44

afr sym._exit 0x00ae34b8
afr sym.doexit 0x00ae33e5
afr sym.exit 0x00ae34a7
afr sym._cexit 0x00ae34c9
afr sym._c_exit 0x00ae34d8
afr sym._amsg_exit 0x00ae3152
afr sym._onexit 0x00ae664d
afr sym.atexit 0x00ae66cf

afr sym.__crtExitProcess 0x00ae3350
afr sym.__crtMessageBoxA 0x00aeb7e4
afr sym.__crtGetEnvironmentStringsA 0x00ae61fa
afr sym.__crtGetLocaleInfoW 0x00b3684d
afr sym.__crtGetLocaleInfoA 0x00b3697d

afr sym.__security_check_cookie.00aeb76f 0x00aeb76f
afr sym.__security_check_cookie.00aeb793 0x00aeb793
afr sym.__security_check_cookie 0x00aeb7a0
afr sym.__security_init_cookie 0x00aee307
afr sym.report_failure 0x00aee35d

afr sym.__crtGetStringTypeA 0x00ae9008
afr sym.__crtGetStringTypeW 0x00b365f0
afr sym.__crtLCMapStringA 0x00aeb15c
afr sym.__crtsetenv 0x00aef40c

afr sym.strtoxl 0x00ae4a40

afr sym.inconsistency.00ae5b9b 0x00ae5b9b
afr sym.inconsistency 0x00b354fc
afr sym.raise 0x00b36af6

afr sym.UnwindNestedFrames 0x00b32852
afr sym.FrameUnwindFilter 0x00b34d10
afr sym.__FrameUnwindToState 0x00b34d29
afr sym.seh_longjmp_unwind 0x00aec001
afr sym.__InternalCxxFrameHandler 0x00b3545a
afr sym.__cxxframehandler 0x00b328a4
afr sym.catchguardhandler 0x00b328da
afr sym.translatorguardhandler 0x00b328fe

afr sym.__FrameUnwindToState.00b34dd6 0x00b34dd6
afr sym.__FrameUnwindToState.00b35529 0x0x00b35529
afr sym.__InternalCxxFrameHandler.00b35283 0x00b35283
afr sym.__InternalCxxFrameHandler.00b351c1 0x00b351c1
afr sym.CatchIt.00b34e48 0x00b34e48
afr sym.CatchIt.00b34f80 0x00b34f80

afr sym.isdigit 0x00aeb584
afr sym.isspace 0x00aeb5ad
afr sym.nanf 0x00422a70

afr sym.j__free 0x00b31b8c
afr sym._flush.00ae83cd 0x00ae83cd

f sym._vsnprintf.00ae68ad 1909 0x00ae68ad
af+ 0x00ae68ad sym._vsnprintf.00ae68ad f n
afu 0x00ae7022 @ 0x00ae68ad

afr sym._vsnprintf 0x00ae34e7
afr sym.sprintf 0x00ae353d
afr sym.vsprintf 0x00ae3986
afr sym.fprintf 0x00ae3d1d

afr sym.sscanf 0x00ae311e
afr sym.sscanf.00ae4f69 0x00ae4f69

afr sym.fclose 0x00ae3740
afr sym.fread 0x00ae3796
afr sym.fwrite 0x00ae387f
afr sym.fgetpos 0x00ae3d4f
afr sym.fsetpos 0x00ae3d71
afr sym.fseek 0x00ae3f69
afr sym.ftell 0x00ae44b9
afr sym.fflush 0x00ae7ef4
afr sym.flsall 0x00ae7f2f
afr sym._filbuf 0x00ae7fa5
afr sym._flsbuf 0x00ae6709
afr sym._flush 0x00ae7e97
afr sym._flushall 0x00ae7f9c
afr sym._fseeki64 0x00ae87cd
afr sym._fsopen 0x00ae3703
afr sym._ftbuf 0x00ae8609
afr sym._ftelli64 0x00ae8645

afr sym.__DestructExceptionObject 0x00b34de6
afr sym._CallSettingFrame_12 0x00b35560
afr sym._CIpow.00ae47ed 0x00ae47ed
afr sym._CIpow.00ae9689 0x00ae9689
afr sym._CIpow.00ae4865 0x00ae4865
afr sym._CIpow.00ae48ca 0x00ae48ca
afr sym._CIpow.00ae9572 0x00ae9572
afr sym._CIpow.00ae9539 0x00ae9539
afr sym._CIpow 0x00ae4790
afr sym._CopyMan 0x00aee975
afr sym._FF_MSGBANNER 0x00ae5d12
afr sym._IncMan 0x00aee8b6
afr sym._IsZeroMan 0x00aee990
afr sym._RoundMan 0x00aee903
afr sym._RTC_Initialize 0x00ae64c7
afr sym._ShrMan 0x00aee9a9
afr sym._XcptFilter 0x00ae5d4b
afr sym._ZeroTail 0x00aee884

afr sym.AdjustPointer 0x00b34e2b
afr sym.BuildCatchObject 0x00b34fde
afr sym.BuildCatchObject.00b3284b 0x00b3284b
afr sym.CallCatchBlock2 0x00b32a56
afr sym.CallSETranslator 0x00b32aa7
afr sym.CatchIt 0x00b3515a
afr sym.CPtoLCID 0x00aebb46
afr sym.CreateFrameInfo 0x00b329e9
afr sym.FindAndUnlinkFrame 0x00b32a1d
afr sym.GetLcidFromCountry.00b3441f 0x00b3441f
afr sym.GetLcidFromCountry 0x00b34821
afr sym.GetLcidFromDefault 0x00b34236
afr sym.GetLcidFromLangCountry.00b34530 0x00b34530
afr sym.GetLcidFromLangCountry 0x00b34858
afr sym.GetLcidFromLanguage.00b34750 0x00b34750
afr sym.GetLcidFromLanguage 0x00b348de
afr sym.GetPrimaryLen 0x00b34402
afr sym.GetRangeOfTrysToCheck 0x00b3296f
afr sym.IsExceptionObjectToBeDestroyed 0x00b32a02
afr sym.JumpToContinuation 0x00b3281b
afr sym.LcidFromHexString 0x00b343cd
afr sym.TestDefaultCountry 0x00b342cc
afr sym.TranslateName 0x00b341d6
afr sym.TypeMatch 0x00b34cc1
afr sym.ValidateExecute 0x00b365c0
afr sym.ValidateRead 0x00b365a4

af sym.WinMainCRTStartup 0x00ae3177

afr sym.__add_12 0x00aef5e2
afr sym.__addl 0x00aef5c1
afr sym.__ascii_stricmp 0x00b35730
afr sym.__dtold 0x00aeeca5
afr sym.__free_lconv_mon 0x00b33d55
afr sym.__free_lconv_num 0x00b33bcf
afr sym.__get_qualified_locale.00ae30c9 0x00ae30c9
afr sym.__get_qualified_locale.00b344b9 0x00b344b9
afr sym.__get_qualified_locale.00b34250 0x00b34250
afr sym.__get_qualified_locale 0x00b34933
afr sym.__heap_select 0x00ae654f
afr sym.__initmbctable 0x00aebf1c
afr sym.__initmbctable.00aebd30 0x00aebd30
afr sym.__initmbctable.00aebb9e 0x00aebb9e
afr sym.__lc_lctostr 0x00b31fac
afr sym.__set_app_type 0x00ae3595
afr sym.__shl_12 0x00aef640
afr sym.__shr_12 0x00aef66e
afr sym.__tzset 0x00ae8e87
afr sym.__wtomb_environ 0x00aee819
afr sym._abstract_cw 0x00aeedd9
afr sym._access 0x00ae367e
afr sym._allmul 0x00aeb7b0
afr sym._alloc_osfhnd 0x00aec6b5
afr sym._aulldiv 0x00ae8fa0
afr sym._aulldvrm 0x00aec350
afr sym._aullshr 0x00b32730
afr sym._cfltcvt_init 0x00ae939a
afr sym._cfto.00aeed5f 0x00aeed5f
afr sym._cfto.00aefc0c 0x00aefc0c
afr sym._cfto.00af016a 0x00af016a
afr sym._cfto.00aeff32 0x00aeff32
afr sym._cftoe 0x00aece84
afr sym._cftof 0x00aecf77
afr sym._cftog 0x00aed054
afr sym._chmod 0x00ae36c2
afr sym._close 0x00ae7db9
afr sym._clrfp 0x00aeb0d1
afr sym._commit 0x00aec87f
afr sym._control87 0x00aeeef9
afr sym._controlfp 0x00aeef2b
afr sym._copysign 0x00ae4cde
afr sym._crt_debugger_hook 0x00ab33a0
afr sym._ctrlfp 0x00aeb0df
afr sym._d_inttype 0x00aea3c7
afr sym._decomp 0x00aea813
afr sym._dosmaperr 0x00ae7b80
afr sym._errcode 0x00aeadba
afr sym._finite 0x00ae4cff
afr sym._fpclass 0x00ae4d42
afr sym._fptostr 0x00aeec2e
afr sym._free_lc_time 0x00b339b3
afr sym._free_osfhnd 0x00aec7c9
afr sym._freebuf 0x00ae7e6c
afr sym._frnd 0x00aee2eb
afr sym._ftol 0x00b31ba0
afr sym._ftol2 0x00b36c20
afr sym._get_exp 0x00aea7a3
afr sym._get_lc_time 0x00b3364c
afr sym._get_lc_time.00b363d0 0x00b363d0
afr sym._get_osfhandle 0x00aec843
afr sym._getbuf 0x00aec1b6
afr sym._getstream 0x00ae7d47
afr sym._handle_exc 0x00aeab72
afr sym._handle_qnan1 0x00aeae87
afr sym._handle_qnan2 0x00aeaed9
afr sym._heap_init 0x00ae6569
afr sym._hextodec 0x00ae4f21
afr sym._hw_cw 0x00aeee6b
afr sym._hypot.00ae9495 0x00ae9495
afr sym._hypot.00ae947c 0x00ae947c
afr sym._hypot.00ae9407 0x00ae9407
afr sym._hypot.00ae9465 0x00ae9465
afr sym._hypot.00aed1ca 0x00aed1ca
afr sym._hypot.00ae46a4 0x00ae46a4
afr sym._hypot 0x00b31b6f
afr sym._hypothlp 0x00b318f8
afr sym._inc 0x00ae4f53
afr sym._ioinit 0x00ae631c
afr sym._isatty 0x00aec1fa
afr sym._isctype 0x00ae4612
afr sym._ismbblead 0x00aebb35
afr sym._ismbcspace 0x00aee74a
afr sym._isnan 0x00ae4d14
afr sym._itoa 0x00b357bc
afr sym._ld12cvt 0x00aeea24
afr sym._ld12tod 0x00aeeb92
afr sym._lseek 0x00ae885f
afr sym._lseeki64 0x00aec8d6
afr sym._mbschr 0x00aefecb
afr sym._mbsnbicoll 0x00aee7da
afr sym._mbsnbicoll.00aecad9 0x00aecad9
afr sym._mbsnbicoll.00aecb22 0x00aecb22
afr sym._mbsnbicoll.00aeefd4 0x00aeefd4
afr sym._mbsrchr 0x00b35806
afr sym._ms_p5_mp_test_fdiv 0x00aed1a1
afr sym._msize 0x00aec17e
afr sym._nlg_notify1 0x00aee575
afr sym._openfile 0x00ae7bdf
afr sym._powhlp 0x00aea431
afr sym._raise_exc 0x00aea8cd
afr sym._read 0x00ae3d89
afr sym._rtonenpop 0x00ae92dd
afr sym._rttosnpopde 0x00ae9389
afr sym._set_errno 0x00aead94
afr sym._set_exp 0x00aea779
afr sym._set_osfhnd 0x00aec752
afr sym._set_statfp 0x00aeb103
afr sym._setdefaultprecision 0x00aed14f
afr sym._setenvp 0x00ae5f25
afr sym._setjmp3 0x00b31e38
afr sym._setlocale_get_all 0x00b31ffa
afr sym._setmode 0x00aeef41
afr sym._shift 0x00aece67
afr sym._sopen.00aee5ee 0x00aee5ee
afr sym._sopen 0x00aec3e5
afr sym._sptype 0x00aea7b8
afr sym._statfp 0x00aeb0c4
afr sym._stbuf 0x00ae8581
afr sym._strcats 0x00b31eb6
afr sym._strdup 0x00aefea0
afr sym._stricmp 0x00b32cf8
afr sym._strtoui64 0x00ae4bed
afr sym._trandisp1 0x00ae91d0
af sym._trandisp2 0x00ae9237
afr sym._tzset 0x00ae88eb
afr sym._ultoa 0x00b357e6
afr sym._umatherr.00b31eb3 0x00b31eb3
afr sym._umatherr 0x00aeade7
afr sym._wfopen 0x00ae372d
afr sym.atam.00ae94fb 0x00ae94fb
afr sym.atam.00aed2c8 0x00aed2c8
afr sym.atan 0x00b331c0
afr sym.atol 0x00aec975
afr sym.bsearch 0x00b3347e
afr sym.copy_environ 0x00aef3ab
afr sym.cvtdate 0x00ae8b3e
afr sym.fabs.00aeaf37 0x00aeaf37
afr sym.fabs 0x00b33310
afr sym.findenv 0x00aef35e
afr sym.genfname 0x00b32d9c
afr sym.getenv 0x00aeca58
afr sym.gmtime 0x00ae8e9c
afr sym.has_osfxsr_set 0x00ae95dc
afr sym.init_namebuf 0x00b32d3b
afr sym.iswalpha 0x00b32b73
afr sym.iswctype 0x00b355ac
afr sym.iswdigit 0x00b32b84
afr sym.iswpunct 0x00b32ba0
afr sym.iswspace 0x00b32b92
afr sym.ldexp.00aeaff5 0x00aeaff5
afr sym.ldexp 0x00aea593
afr sym.localtime.00ae8cf6 0x00ae8cf6
afr sym.localtime 0x00ae4300
afr sym.longjmp.00b3360a 0x00b3360a
afr sym.longjmp 0x00b31dbc
afr sym.mbtowc 0x00aeb5d6
afr sym.parse_cmdline 0x00ae5fec
afr sym.pow.00ae93f0 0x00ae93f0
afr sym.pow.00ae9450 0x00ae9450
afr sym.pow 0x00ae4750
af- fcn.00ae94ee;f- @ 0x00ae94ee;afr sym.pow.00ae94ee 0x00ae94ee
afr sym.rand 0x00ae359f
afr sym.setSBCS 0x00aebb75
afr sym.shortsort 0x00ae4000
afr sym.siglookup 0x00b36abd
af sym.start 0x00b33258
afr sym.test_whether_TOS_is_int 0x00ae49b2
afr sym.time 0x00ae4480
afr sym.tolower 0x00ae4ddc
afr sym.ungetc 0x00aeb518
afr sym.wctomb 0x00aec2db
afr sym.write_char 0x00ae681f
afr sym.write_multi_char 0x00ae6852
afr sym.write_string 0x00ae6876
afr sym.x_ismbbtype 0x00aebb04
afr sym.xtoa 0x00b3577e

af sym.strcat 0x00aeb8f0

# af sym.j_allocmemory.00425d00 0x00425d00
# af sym.j_allocmemory.00ab1fc0 0x00ab1fc0
# af sym.j_allocmemory.00494240 0x00494240
#
# af sym._cisqrt.00ae46ad 0x00ae46ad
# af sym.cintrinexit.00aed1ca 0x00aed1ca
# af sym._fassign.00aeebeb 0x00aeebeb
# af sym._fassign.00aeeba8 0x00aeeba8
# af sym._fassign.00aeeb7c 0x00aeeb7c
# af sym._fassign.00aef77f 0x00aef77f

# af sym._cfltcvt_init 0x004340c0
# af sym.j_allocmemory 0x0044dd60
# af sym.dialogfunc 0x00ac6000
# af sym._strnicmp 0x00ae30c9
# af sym._cisqrt 0x00ae4690
# af sym.sqrt 0x00ae46a4
# af sym.__ascii_strnicmp 0x00ae4ec0
# af sym._flush.00ae83cd 0x00ae83cd
# af sym.localtime.00ae8cf6 0x00ae8cf6
# af sym._rttosnpop 0x00ae92cc
# af sym._starttwoargerrorhandling 0x00ae93f0
# af sym._startoneargerrorhandling 0x00ae9407
# af sym._twototos 0x00ae9450
# af sym._load_cw 0x00ae9465
# af sym._converttostoqnan 0x00ae947c
# af sym._fload_withfb 0x00ae9495
# af sym._checktos_withfb 0x00ae94d8
# af sym._check_overflow_exit 0x00ae9525
# af sym._check_range_exit 0x00ae9539
# af sym._cipow_pentium4 0x00ae9670
# af sym._pow_pentium4 0x00ae9689
# af sym.zerotoxdone 0x00aea2a7
# af sym.expbigret 0x00aea2f2
# af sym._rtinfnpop 0x00aea301
# af sym._ffexpm1 0x00aea31e
# af sym.isinttos 0x00aea361
# af sym.isinttosret 0x00aea386
# af sym.noerror 0x00aea3c6
# af sym._forcdecpt 0x00aecd6c
# af sym._fassign 0x00aece29
# af sym._cfltcvt 0x00aed0fe
# af sym._ms_p5_test_fdiv 0x00aed161
# af sym._fptrap 0x00aee2fe
af sym._abnormal_termination 0x00aee552
# af sym._fcloseall 0x00aee596
# af sym.ceil 0x00b31bd0
# af sym._ciacos 0x00b31cf0
# af sym.acos 0x00b31d04
# af sym.start_2 0x00b31d0d
# af sym.floor 0x00b32600
# af sym._ciasin 0x00b32750
# af sym.asin 0x00b32764
# af sym.start_3 0x00b3276d
# af sym._eh_prolog 0x00b32b54
# af sym.modf 0x00b32bb0
# af sym.return 0x00b32c88
# af sym.call_libm_error_0 0x00b32cc8
# af sym.asin_0 0x00b32ed8
# af sym.acos_0 0x00b32ee2
# af sym.atan 0x00b32ee9
# af sym.atan2 0x00b32ef0
# af sym.exp 0x00b32f30
# af sym._cicos 0x00b32fc0
# af sym.cos 0x00b32fd4
# af sym.start_4 0x00b32fdd
# af sym.log 0x00b33070
# af sym._cisin 0x00b333d0
# af sym.sin 0x00b333e4
# af sym.start_7 0x00b333ed
# af sym.remove 0x00b3350a
# af sym.j__remove 0x00b33534
# af sym.rt_probe_read4 0x00b3360a
# af sym.__init_time 0x00b33b43
# af sym.__init_numeric 0x00b33c0f
# af sym.__init_monetary 0x00b33dde
# af sym.crtgetlocaleinfoa 0x00b342ea
# af sym.localeenumproc 0x00b3441f
# af sym._modf_default 0x00b35606
# af sym._rmtmp 0x00b3585c
# af sym._ffsinh 0x00b358a0
# af sym.rtforcnhlarge 0x00b35935
# af sym.ffexph 0x00b35948
# af sym.exphypsum 0x00b35979
# af sym.exphypsumreturn 0x00b3598a
# af sym.exphypcopyinv 0x00b3598b
# af sym._cintrindisp2 0x00b359a0
# af sym._cintrindisp1 0x00b359de
# af sym._ctrandisp2 0x00b35a14
# af sym.ctranexit 0x00b35a4e
# af sym.cintrinexit 0x00b35a55
# af sym._ctrandisp1 0x00b35b9a
# af sym._fload 0x00b35bc6
# af sym._ciexp_pentium4 0x00b35c10
# af sym.start_8 0x00b35c2e
# af sym._cilog_pentium4 0x00b35ed0
# af sym.start_9 0x00b35eee
# af sym._cilog10_pentium4 0x00b36140
# af sym.start_10 0x00b3615e
# af sym._cxxunhandledexceptionfilter 0x00b36522
af sym.validateread 0x00b36588
# af sym.validatewrite 0x00b365a4
# af sym.validateexecute 0x00b365c0
# af sym._ctrandisp2.00ae9237 0x00ae9237
# af sym.start_11 0x00aed2c8


afr sym.jade_parse_int32 0x00427b50
afvr edx input uint8_t ** @ 0x00427b50
afvr esi output int32_t * @ 0x00427b50
afvs 0x8 flags uint8_t @ 0x00427b50

afr sym.jade_parse_int16 0x00427b90
afvr edx input uint8_t ** @ 0x00427b90
afvr esi output int16_t * @ 0x00427b90
afvs 0x8 flags uint8_t @ 0x00427b90

afr sym.jade_parse_float 0x00427bd0
afvr ecx input uint8_t ** @ 0x00427bd0
afvr edx output float * @ 0x00427bd0
afvs 0x8 flags uint8_t @ 0x00427bd0

afr sym.jade_parse_vec3f 0x00427cc0
afvr ecx input uint8_t ** @ 0x00427cc0
afvr esi output float * @ 0x00427cc0
afvs 0x8 flags uint8_t @ 0x00427cc0

afr sym.jade_parse_vec4f 0x00427df0
afvr ecx input uint8_t ** @ 0x00427df0
afvr esi output float * @ 0x00427df0
afvs 0x8 flags uint8_t @ 0x00427df0

afr sym.jade_parse_transform 0x00427d10
afvr ecx input uint8_t ** @ 0x00427d10
afvr edi output float * @ 0x00427d10
afvs 0x8 flags uint8_t @ 0x00427d10

afr sym.jade_parse_int8 0x00433da0
afvr edx input uint8_t ** @ 0x00433da0
afvr esi output int8_t * @ 0x00433da0
afvs 0x8 flags uint8_t @ 0x00433da0

afr sym.jade_malloc.00425d00 0x00425d00
afr sym.jade_malloc.00494240 0x00494240
afr sym.jade_malloc.00ab1fc0 0x00ab1fc0
afr sym.jade_malloc 0x00425f30
afvs 0x8 size size_t @ 0x00425f30

afr sym.jade_malloc_tracked 0x00426320
afvr eax size size_t @ 0x00426320

afr sym.jade_wow_alloc 0x0045e3e0

afr sym.jade_are_globals_not_0_and_2 0x00416ae0

afr sym.jade_normalize_vec3f 0x00429550
afr sym.jade_normalize_rotation 0x00429770
afr sym.jade_make_identity_matrix 0x00409ab0
afr sym.jade_validate_transform 0x00ac8ed0
afr sym.jade_are_points_within_range 0x00425a00

afr sym.jade_insert_in_global_double_linked_list 0x00ac8240
afr sym.jade_create_wow_subnode 0x0047b1d0
afr sym.jade_create_wow_node 0x0047b480
afr sym.jade_push_parser 0x00421e00

afr sym.jade_binary_search_from_global_list 0x004280e0
afr sym.jade_binary_search_by_id 0x00427410

afr sym.jade_read_at 0x004277a0
afr sym.jade_read_at_expect 0x00427830
afr sym.jade_read_at_chunk 0x004278d0

afr sym.jade_read_at.00426060 0x00426060
afr sym.jade_read_at.004263c0 0x004263c0
afr sym.jade_read_at.00432ce0 0x00432ce0
afr sym.jade_read_at.00432df0 0x00432df0

afr sym.jade_read_at.00426d90 0x00426d90
afr sym.jade_read_at.004265d0 0x004265d0
afr sym.jade_read_at.00426690 0x00426690
afr sym.jade_read_at.00429390 0x00429390
afr sym.jade_read_at.00494200 0x00494200
afr sym.jade_read_at.0042a540 0x0042a540

afr sym.jade_read_at_chunk.00426570 0x00426570
afr sym.jade_read_at_chunk.00426770 0x00426770
afr sym.jade_read_at_chunk.00427a90 0x00427a90
afr sym.jade_read_at_chunk.00426450 0x00426450

afr sym.jade_report_error 0x00428100

af sym.jade_report_error.00428440 0x00428440
afr sym.jade_report_error.00422620 0x00422620
afr sym.jade_report_error.00429dc0 0x00429dc0
afr sym.jade_report_error.00495d40 0x00495d40
afr sym.jade_report_error.00495490 0x00495490
afr sym.jade_report_error.004288a0 0x004288a0
afr sym.jade_report_error.00495b60 0x00495b60

af sym.fsetpos 0x00ae3d71

afr sym.jade_parse_wow 0x00466690

afr sym.jade_parse_wow.0047d720 0x0047d720
afr sym.jade_parse_wow.00422300 0x00422300
afr sym.jade_parse_wow.0045e490 0x0045e490
afr sym.jade_parse_wow.0045e280 0x0045e280
afr sym.jade_parse_wow.00465580 0x00465580
afr sym.jade_parse_wow.00427620 0x00427620

afr sym.jade_parse_wow.0045e220 0x0045e220

afr sym.jade_parse_wax_sxx 0x0041e190

afr sym.jade_parse_wax_sxx.0041d900 0x0041d900
afr sym.jade_parse_wax_sxx.0041d310 0x0041d310
afr sym.jade_parse_wax_sxx.0041b090 0x0041b090
afr sym.jade_parse_wax_sxx.00420270 0x00420270
afr sym.jade_parse_wax_sxx.00419a20 0x00419a20
afr sym.jade_parse_wax_sxx.00420730 0x00420730
afr sym.jade_parse_wax_sxx.00420770 0x00420770
afr sym.jade_parse_wax_sxx.00ae30c9 0x00ae30c9
afr sym.jade_parse_wax_sxx.00414d90 0x00414d90
afr sym.jade_parse_wax_sxx.00414d20 0x00414d20
afr sym.jade_parse_wax_sxx.00416820 0x00416820
afr sym.jade_parse_wax_sxx.0041af10 0x0041af10
afr sym.jade_parse_wax_sxx.00427c20 0x00427c20
afr sym.jade_parse_wax_sxx.00427830 0x00427830
afr sym.jade_parse_wax_sxx.0041e8b0 0x0041e8b0
afr sym.jade_parse_wax_sxx.0041d470 0x0041d470
afr sym.jade_parse_wax_sxx.0041b040 0x0041b040
afr sym.jade_parse_wax_sxx.0041b070 0x0041b070

afr sym.jade_parse_wax_sxx.0041d730 0x0041d730
afr sym.jade_parse_wax_sxx.0041afa0 0x0041afa0
afr sym.jade_parse_wax_sxx.004166f0 0x004166f0
afr sym.jade_parse_wax_sxx.004177b0 0x004177b0
afr sym.jade_parse_wax_sxx.00417d60 0x00417d60
afr sym.jade_parse_wax_sxx.00417c50 0x00417c50
afr sym.jade_parse_wax_sxx.004275b0 0x004275b0

afr sym.jade_parse_gao 0x0046ba50

afr sym.jade_parse_gao.00469660 0x00469660
afr sym.jade_parse_gao.00426540 0x00426540
afr sym.jade_parse_gao.0047dac0 0x0047dac0
afr sym.jade_parse_gao.00460b60 0x00460b60
afr sym.jade_parse_gao.00475940 0x00475940
afr sym.jade_parse_gao.00490660 0x00490660

afr sym.jade_gao_create_object_0 0x00468730
afr sym.jade_gao_create_object_1 0x00476900
afr sym.jade_gao_create_translation 0x00490d00
afr sym.jade_gao_fill_structure_0 0x0047db20

afr sym.jade_parse_ova_ofc 0x004a61f0

afr sym.jade_parse_snk 0x0041e570
afr sym.jade_parse_snk.0041e610 0x0041e610

afr sym.jade_open_data 0x00421cf0
afr sym.jade_close_data 0x00421d90

afr sym.jade_open_data.00428c50 0x00428c50
afr sym.jade_open_data.00428f30 0x00428f30

afr sym.jade_open_data.004276a0 0x004276a0
afr sym.jade_open_data.00ae4070 0x00ae4070
afr sym.jade_open_data.00428da0 0x00428da0
afr sym.jade_open_data.004274b0 0x004274b0

afr sym.jade_get_wow_element_id 0x00422420

f var.__global_wait_handle 4 0xb7ad3c
f var.__global_constant_128 1 0xb6453c
f var.__global_allocated_size_2 4 0xb8a124
f var.__global_allocated_size 4 0xb8a128
f var.__global_double_linked_list.head 4 0xd4af80
f var.__global_double_linked_list.tail 4 0xd4af84
f var.__global_double_linked_list.size 4 0xd4af88
f var.__global_double_linked_list 12 0xd4af80
f var.__global_list 8 0xb8cdd4
f var.__global_list_ptr 4 0xb89fc4
f var.__invalid_rotation_1 12 0xb7ad40
f var.__invalid_rotation_2 12 0xb7ad50
f var.__invalid_rotation_3 12 0xb7ad60
f var.__invalid_translate1_0 4 0xbab960
f var.__invalid_translate1_1 4 0xbab964
f var.__invalid_translate1_2 4 0xbab968
f var.__invalid_translate1 12 0xbab960
f var.__invalid_translate2 12 0xbb09a0
f var.___should_not_be_0 4 0xb8a150
f var.___should_be_2 4 0xb89fc8
f var.__wow_list_last 4 0xb8a144
f var.__global_wow001 4 0xb8a148
f var.__wow_list_count 4 0xb8a14c
f var.__wow_list 0x1388 0xb8de00
f var.__global_wow020 4 0xb6454c
f var.__global_wow030 4 0xd13274
f var.__global_gao000 4 0xb8a0fc
f var.__global_gao001 4 0xb8a118
f var.__global_gao002 4 0xb8a118
f var.__global_gao003 4 0xd14940
f var.__global_wax000 4 0xb79e00
f var.__global_wax001 4 0xb8c450
f var.__global_ofc000 4 0xb8a120
f var.__global_snk000 4 0xb8cdd0
f var.__global_epsilon 4 0xb4ffc4
f var.__global_one 4 0xb4ffd8

af- 0x007ffe00;f- @ 0x007ffe00
f~fcn
