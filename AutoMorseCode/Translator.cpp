#include "Translator.h"
#include "Morse.h"
#include <Windows.h>
#include <string>
#include <stdio.h>

void Translator::SendIambicKeys(int WPM)
{
	// T = 1200 / W
	uint32_t TimeUnit = 1200 / WPM;

	// Input struct
	static INPUT input;
	ZeroMemory(&input, sizeof(INPUT));
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = VK_OEM_PERIOD;
	input.ki.dwFlags = 0;

	bool keys[2] = { false, false };
	do {
		(GetAsyncKeyState(IAMBIC_DIT) & 0x8000) ? keys[0] = true : keys[0] = false;
		if (keys[0]) {
			input.ki.dwFlags = 0;
			SendInput(1, &input, sizeof(INPUT));
			Sleep(50 + TimeUnit);
			input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &input, sizeof(INPUT));
			Sleep(TimeUnit);
		}
		(GetAsyncKeyState(IAMBIC_DAH) & 0x8000) ? keys[1] = true : keys[1] = false;
		if (keys[1]) {
			input.ki.dwFlags = 0;
			SendInput(1, &input, sizeof(INPUT));
			Sleep(50 + TimeUnit * 3);
			input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &input, sizeof(INPUT));
			Sleep(TimeUnit);
		}
		
	} while (keys[0] || keys[1]);
}

void Translator::TranslateAndSend(int WPM, char* Message)
{
	// T = 1200 / W
	uint32_t TimeUnit = 1200 / WPM;

	for (uint32_t i = 0; i < strlen(Message); i++)
	{
		srand(i);
		if (GetAsyncKeyState(VK_F4)) { break; }

		if (Message[i] == ' ') // Medium pause; 7 units
		{
			printf("/ ");
			Sleep(TimeUnit * 7);
			continue;
		}
		if (islower(Message[i]) || isupper(Message[i]))
		{
			bool lower = islower(Message[i]);
			char* pattern = (char*)morse::_alphabet[Message[i] - ((lower) ? 97 : 65)];
			SendCharacter(TimeUnit, pattern);
		}
		else
		{
			for (int j = 0;; j++)
			{
				if (morse::_symbols[j] != nullptr)
				{
					char* pattern = (char*)morse::_symbols[j];
					if (pattern[0] == Message[i]) {
						SendCharacter(TimeUnit, (char*)(pattern + 1));
						break;
					}
				}
				else { break; }
			}
		}
		Sleep(TimeUnit * 2);
		printf(" ");
	}
	printf("\n");

}

void Translator::SendCharacter(int TimeUnit, char * CharacterPattern)
{
	// Input struct
	static INPUT input;
	ZeroMemory(&input, sizeof(INPUT));
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = VK_OEM_PERIOD;
	input.ki.dwFlags = 0;

	for (uint32_t j = 0; j < strlen(CharacterPattern); j++)
	{
		if (CharacterPattern[j] == dit) // Short dash; 1 unit
		{
			printf(".");
			input.ki.dwFlags = 0;
			SendInput(1, &input, sizeof(INPUT));
			Sleep(50 + TimeUnit * 1.5);
			input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &input, sizeof(INPUT));
		}
		else if (CharacterPattern[j] == dah) // Long dash; 3 units
		{
			printf("-");
			input.ki.dwFlags = 0;
			SendInput(1, &input, sizeof(INPUT));
			Sleep(50 + TimeUnit * 3);
			input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &input, sizeof(INPUT));
		}
		Sleep(TimeUnit); // Inter-element pause; 1 unit
	}
	Sleep(TimeUnit); // Inter-letter pause;
}
