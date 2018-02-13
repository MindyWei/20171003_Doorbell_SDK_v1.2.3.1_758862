#include <unistd.h>
#include "SDL/SDL.h"
#include "ite/itp.h"
#include "project.h"
#include "scene.h"
#include "function_user.h"

int SDL_main(int argc, char *argv[])
{
	int ret = 0;

#ifdef CFG_CHECK_FILES_CRC_ON_BOOTING
	int restryCount = 0;

	BackupInit();
retry_backup:
	ret = UpgradeInit();
	if (ret)
	{
		if (++restryCount > 2)
		{
			printf("cannot recover from backup....\n");
			goto end;
		}
		BackupRestore();
		goto retry_backup;
	}
	BackupSyncFile();
#else
	ret = UpgradeInit();
	if (ret)
		goto end;
#endif

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());

	ConfigInit();
#ifdef CFG_NET_ENABLE
	NetworkInit();
#endif
	
	PhotoInit();
	StorageInit();
	SceneInit();
	AudioInit();
	SceneLoad();


	user_gpio_init();
	//HW_v6502_test();
	user_timer_init();
	user_pr2000_init();
	user_TestFunc_init();
	user_call_init();
	HOOK_ON_init();

	AudioSetVolume(60);
	//user_ring_init();
	//SAT_BOARD_INIT();
	
	ret = SceneRun();

	SceneExit();
	AudioExit();
	ConfigExit();
	SDL_Quit();

end:
	ret = UpgradeProcess(ret);
	exit(ret);
	return ret;
}
