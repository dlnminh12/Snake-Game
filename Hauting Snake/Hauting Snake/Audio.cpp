#include"audio.h"
#include"header.h"
bool isSoundPlaying = false; // co kiem tra nhac co dang choi de ko bi lap
void EatSound()
{ 
	if(SFX_OPS==1)
	PlaySound(TEXT("eating.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void DeadSound()
{
	if(SFX_OPS==1)
	PlaySound(TEXT("bonk.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void MenuSound()
{
		if (MUSIC_OPS == 1)
		{
			if (!isSoundPlaying)// neu nhac dang choi thi khong replay lai menusound
			{
				DWORD volumeMenu = 12000;
				waveOutSetVolume(NULL, MAKELONG(volumeMenu, volumeMenu));
				PlaySound(TEXT("intro.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				isSoundPlaying = true;
			}
		}
		else
			StopSound();
}
void StopSound() // tat tieng
{
	PlaySound(NULL, NULL, SND_ASYNC);
	isSoundPlaying = false; // gan lai de neu bat am thanh len lai thi nhac lai choi
}
void ToggleSound()
{
	if (SFX_OPS == 1)
	{
		DWORD volumeToggle = 20000;
		waveOutSetVolume(NULL, MAKELONG(volumeToggle, volumeToggle));
		PlaySound(TEXT("jump.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
}
void BonusSound()
{
	if (SFX_OPS == 1)
	{
		DWORD volumeToggle = 20000;
		waveOutSetVolume(NULL, MAKELONG(volumeToggle, volumeToggle));
		PlaySound(TEXT("bonus.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
}
void LoadBarSound()
{
		DWORD volumeToggle = 20000;
		waveOutSetVolume(NULL, MAKELONG(volumeToggle, volumeToggle));
		PlaySound(TEXT("load.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void CountDownSound()
{
	DWORD volumeToggle = 20000;
	waveOutSetVolume(NULL, MAKELONG(volumeToggle, volumeToggle));
	PlaySound(TEXT("countdown.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void GameOverSound()
{
	DWORD volumeToggle = 20000;
	waveOutSetVolume(NULL, MAKELONG(volumeToggle, volumeToggle));
	PlaySound(TEXT("gameover.wav"), NULL, SND_FILENAME | SND_ASYNC);
}


