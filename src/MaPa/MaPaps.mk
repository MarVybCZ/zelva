
MaPaps.dll: dlldata.obj MaPa_p.obj MaPa_i.obj
	link /dll /out:MaPaps.dll /def:MaPaps.def /entry:DllMain dlldata.obj MaPa_p.obj MaPa_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del MaPaps.dll
	@del MaPaps.lib
	@del MaPaps.exp
	@del dlldata.obj
	@del MaPa_p.obj
	@del MaPa_i.obj
