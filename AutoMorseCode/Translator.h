#pragma once

#include <cstring>
#include <cinttypes>

#define SEND_KEY VK_F2
#define CANCEL_KEY VK_F4
#define IAMBIC_DIT 0x4A
#define IAMBIC_DAH 0x4B

void SendIambicKeys(int WPM);
void TranslateAndSend(int WPM, char* Message);
void SendCharacter(int TimeUnit, char* CharacterPattern);