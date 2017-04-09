#include <stdio.h>
#include "Form.h"

using namespace CommonSettings;

// �v���O������ android_main ����n�܂�܂�
int android_main(void)
{
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);//�E�B���h�E�T�C�Y
	if (DxLib_Init() == -1) {
		return -1;
	}

	Form Fmain;

	// �`���𗠉�ʂɕύX
	SetDrawScreen(DX_SCREEN_BACK);
	while (1) {
		if (ProcessMessage() != 0 || keyInput.getPressFrame(KEY_INPUT_ESCAPE)) {
			break;//�E�B���h�E�́~�{�^���܂���Esc�L�[�����ꂽ�烋�[�v�𔲂���
		}
		ClearDrawScreen();

		//�L�[�{�[�h, �}�E�X�̏�Ԃ��X�V
		keyInput.update();
		mouseInput.update();
		touchInput.update();

		if (!Fmain.update()) {
			break;
		}
		ScreenFlip();//����ʂ𔽉f
	}

	DxLib_End();
	return 0;
}