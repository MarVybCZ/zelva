
InterComps.dll: dlldata.obj InterCom_p.obj InterCom_i.obj
	link /dll /out:InterComps.dll /def:InterComps.def /entry:DllMain dlldata.obj InterCom_p.obj InterCom_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del InterComps.dll
	@del InterComps.lib
	@del InterComps.exp
	@del dlldata.obj
	@del InterCom_p.obj
	@del InterCom_i.obj
