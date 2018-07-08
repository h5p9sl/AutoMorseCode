#include <iostream>
#include <string>
#include <Windows.h>

#include "Translator.h"


int main()
{
	puts("Use \'J\'(dit) and \'L\'(dah) keys to send iambic keys after determining WPM.");

	int WPM = 0;
	while (true)
	{
		char input[1024];
		puts("Words per minute?");
		std::cin.getline(input, sizeof(input));
		WPM = std::stoi(std::string(input));
		puts("Message? (leave blank if iambic keying)");
		std::cin.getline(input, sizeof(input));
		puts("Press F2 when ready for keystrokes to be sent. Press F4 to cancel\nIf iambic keying, start keying now.");

		bool send = true;

		while (!GetAsyncKeyState(SEND_KEY))
		{
			if (GetAsyncKeyState(CANCEL_KEY)) {
				send = false;
				break;
			}
			SendIambicKeys(WPM);
			Sleep(5);
		}
		if (send) {
			TranslateAndSend(WPM, input);
		}
	}
	return 0;
}