#include <iostream>
#include <string>
#include <Windows.h>

#include "Translator.h"

// This is some horrible code and I think I might rewrite all of it... soon

int main()
{
    Translator translator;

	puts("Use \'J\'(dit) and \'K\'(dah) keys to send iambic keys after determining WPM.");

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
            translator.SendIambicKeys(WPM);
			Sleep(5);
		}
		if (send) {
			translator.TranslateAndSend(WPM, input);
		}
	}
	return 0;
}