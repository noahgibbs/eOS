# include <status.h>

/* Systems to import or write:

   * Logging
   * Loading/modules/boot
   * Settings

   */

private void load_sys_files()
{
	mixed *dir_info;
	int i, sz;

	dir_info = get_dir("/usr/System/sys");
	sz = sizeof(dir_info[0]);
	for(i = 0; i < sz; i++) {
		object ob;
		ob = compile_object("/usr/System/sys/" + dir_info[0][i]);
		::call_other(ob, "???");
	}
}

static void create()
{
	object ob;
	ob = compile_object("/usr/System/boot");
	::call_other(ob, "???");

	load_sys_files();
}
