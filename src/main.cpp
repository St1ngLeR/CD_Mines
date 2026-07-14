#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>

#include <set>
#include <unordered_map>
#include <string>
#include <sstream>
#include <random>

#include "injector/injector.hpp"

void __declspec(naked) a_MinesShop()
{
    __asm
    {
        je loc_533A65

        cmp al, 03  // 3 - mines
        je loc_533A65

        jmp loc_533942

    loc_533A65:
        push 0x533A65
        retn

    loc_533942:
        push 0x533942
        retn
    }
}

const char* modesetup_section = "gametext/modesetup.txt";

const char* weaponsall_key = "WEAPONSALL";
const char* weaponsall2x_key = "WEAPONSALL2X";
const char* weaponsonlymines_key = "WEAPONSONLYMINES";
const char* weaponsmissilesandmines_key = "WEAPONSMISSILESANDMINES";
const char* weaponsmissiles2xandmines_key = "WEAPONSMISSILES2XANDMINES";

const char* mines_id = "mines";
const char* misssinglemines_id = "misssinglemines";
const char* missdoublemines_id = "missdoublemines";
const char* all_id = "all";
const char* all2x_id = "all2x";

const char* forcemines_str = "forcemines[*]";
const char* forcemines_force = "force";

void __declspec(naked) a_MinesEventSetup()
{
    __asm
    {
        mov eax, ds: [0x7EA2CC]
        mov eax,[eax]
        call AreMinesAvailable
        test al,al
        je skip

        // Mines

        mov ebx,-1
        mov edx, 0x6DCEC4   // NONE
        lea eax,[esp+0xE10]
        call sub_69586C
        mov ebx, weaponsonlymines_key   // WEAPONSONLYMINES
        mov edx, modesetup_section  // gametext/modesetup.txt
        mov ecx,eax
        mov eax,ds: [0x7E3110]
        call sub_66F410
        mov ebx,-1
        mov edx,eax
        lea eax,[esp+0x1180]
        call sub_69586C
        mov ebx,-1
        mov edx, mines_id
        mov edi,eax
        lea eax,[esp+0xE00]
        call sub_69586C
        mov ebx,edi
        mov edx,eax
        mov eax,esi
        call sub_4B3460
        lea eax,[esp+0xE00]
        xor edx,edx
        call sub_6959C9
        lea eax,[esp+0x1180]
        xor edx,edx
        call sub_6959C9
        lea eax,[esp+0xE10]
        xor edx,edx
        call sub_6959C9
        
        // Single Missiles / Mines

        mov ebx,-1
        mov edx, 0x6DCEC4   // NONE
        lea eax,[esp+0xE10]
        call sub_69586C
        mov ebx, weaponsmissilesandmines_key   // WEAPONSMISSILESANDMINES
        mov edx, modesetup_section  // gametext/modesetup.txt
        mov ecx,eax
        mov eax,ds: [0x7E3110]
        call sub_66F410
        mov ebx,-1
        mov edx,eax
        lea eax,[esp+0x1180]
        call sub_69586C
        mov ebx,-1
        mov edx, misssinglemines_id
        mov edi,eax
        lea eax,[esp+0xE00]
        call sub_69586C
        mov ebx,edi
        mov edx,eax
        mov eax,esi
        call sub_4B3460
        lea eax,[esp+0xE00]
        xor edx,edx
        call sub_6959C9
        lea eax,[esp+0x1180]
        xor edx,edx
        call sub_6959C9
        lea eax,[esp+0xE10]
        xor edx,edx
        call sub_6959C9

        // Double Missiles / Mines

        mov eax, ds: [0x7EA2CC]
        mov eax,[eax]
        call sub_5DA080 // check the availability of missiles
        cmp al, 2
        jl skip2

        mov ebx,-1
        mov edx, 0x6DCEC4   // NONE
        lea eax,[esp+0xE10]
        call sub_69586C
        mov ebx, weaponsmissiles2xandmines_key   // WEAPONSMISSILES2XANDMINES
        mov edx, modesetup_section  // gametext/modesetup.txt
        mov ecx,eax
        mov eax,ds: [0x7E3110]
        call sub_66F410
        mov ebx,-1
        mov edx,eax
        lea eax,[esp+0x1180]
        call sub_69586C
        mov ebx,-1
        mov edx, missdoublemines_id
        mov edi,eax
        lea eax,[esp+0xE00]
        call sub_69586C
        mov ebx,edi
        mov edx,eax
        mov eax,esi
        call sub_4B3460
        lea eax,[esp+0xE00]
        xor edx,edx
        call sub_6959C9
        lea eax,[esp+0x1180]
        xor edx,edx
        call sub_6959C9
        lea eax,[esp+0xE10]
        xor edx,edx
        call sub_6959C9

    skip2:
        // Single Miss. / Mines / Minigun

        mov eax, ds: [0x7EA2CC]
        mov eax,[eax]
        call sub_5DA0A0 // check the availability of minigun
        test al, al
        je skip

        mov ebx,-1
        mov edx, 0x6DCEC4   // NONE
        lea eax,[esp+0xE10]
        call sub_69586C
        mov ebx, weaponsall_key   // WEAPONSALL
        mov edx, modesetup_section  // gametext/modesetup.txt
        mov ecx,eax
        mov eax,ds: [0x7E3110]
        call sub_66F410
        mov ebx,-1
        mov edx,eax
        lea eax,[esp+0x1180]
        call sub_69586C
        mov ebx,-1
        mov edx, all_id
        mov edi,eax
        lea eax,[esp+0xE00]
        call sub_69586C
        mov ebx,edi
        mov edx,eax
        mov eax,esi
        call sub_4B3460
        lea eax,[esp+0xE00]
        xor edx,edx
        call sub_6959C9
        lea eax,[esp+0x1180]
        xor edx,edx
        call sub_6959C9
        lea eax,[esp+0xE10]
        xor edx,edx
        call sub_6959C9
            
        mov eax, ds: [0x7EA2CC]
        mov eax,[eax]
        call sub_5DA080 // check the availability of missiles
        cmp al, 2
        jl skip

        mov ebx,-1
        mov edx, 0x6DCEC4   // NONE
        lea eax,[esp+0xE10]
        call sub_69586C
        mov ebx, weaponsall2x_key   // WEAPONSALL2X
        mov edx, modesetup_section  // gametext/modesetup.txt
        mov ecx,eax
        mov eax,ds: [0x7E3110]
        call sub_66F410
        mov ebx,-1
        mov edx,eax
        lea eax,[esp+0x1180]
        call sub_69586C
        mov ebx,-1
        mov edx, all2x_id
        mov edi,eax
        lea eax,[esp+0xE00]
        call sub_69586C
        mov ebx,edi
        mov edx,eax
        mov eax,esi
        call sub_4B3460
        lea eax,[esp+0xE00]
        xor edx,edx
        call sub_6959C9
        lea eax,[esp+0x1180]
        xor edx,edx
        call sub_6959C9
        lea eax,[esp+0xE10]
        xor edx,edx
        call sub_6959C9

    skip:
        mov ebx, -1
        mov edx,forcemines_str
        lea eax,[esp+0x1300]
        call sub_69586C
        xor ch,ch
        mov edx,0x7A8800
        mov ebx,eax
        lea eax,[esp+0x1140]
        mov [esp+0x17D4],ch
        call sub_677C00
        mov edx,forcemines_force
        xor cl,cl
        call sub_696058
        test eax,eax
        setne bl
        xor edx,edx
        lea eax,[esp+0x1140]
        call sub_6959C9
        lea eax,[esp+0x1300]
        xor edx,edx
        call sub_6959C9
        test bl,bl
        je skip3
        mov [esp+0x17D4],1

    skip3:
        mov ebx, -1
        jmp loc_5830CA

    AreMinesAvailable:
        push edx
        mov edx,[eax+0x1D]
        sar edx,0x18
        imul edx,edx,0x7B64
        mov al,[edx+eax+0x7B87]
        pop edx
        ret

    sub_696058:
        push 0x696058
        retn

    sub_677C00:
        push 0x677C00
        retn

    sub_5DA0A0:
        push 0x5DA0A0
        retn

    sub_5DA080:
        push 0x5DA080
        retn

    sub_4B3460:
        push 0x4B3460
        retn

    sub_6959C9:
        push 0x6959C9
        retn

    sub_66F410:
        push 0x66F410
        retn

    sub_69586C:
        push 0x69586C
        retn

    loc_5830CA:
        push 0x5830CA
        retn
    }
}

void __declspec(naked) a_MinesEventInfoMP()
{
    __asm
    {
        xor edx, edx
        call sub_6959C9
        mov ebx, -1
        mov edx, forcemines_str
        lea eax, [esp + 0x2B0]
        call sub_69586C
        mov edx, 0x7A7764
        mov ebx, eax
        lea eax, [esp + 0xD0]
        call sub_677C00
        mov edx, forcemines_force
        call sub_696058
        test eax, eax
        setne bl
        xor edx, edx
        lea eax, [esp + 0xD0]
        call sub_6959C9
        lea eax, [esp + 0x2B0]
        xor edx, edx
        call sub_6959C9
        test bl, bl
        je go_to_minigun

        xor edx, edx
        call sub_6959C9
        mov ebx, -1
        mov edx, 0x6D6276   // forcemissile[*]
        lea eax, [esp + 0x2B0]
        call sub_69586C
        mov edx, 0x7A7764
        mov ebx, eax
        lea eax, [esp + 0xD0]
        call sub_677C00
        mov edx, 0x6D6227   // single
        call sub_696058
        test eax, eax
        setne bl
        xor edx, edx
        lea eax, [esp + 0xD0]
        call sub_6959C9
        lea eax, [esp + 0x2B0]
        xor edx, edx
        call sub_6959C9
        test bl, bl
        je go_to_missdoublemines
        jmp go_to_misssinglemines

    go_to_misssinglemines:
        xor edx, edx
        call sub_6959C9
        mov ebx, -1
        mov edx, 0x6D6217   // forceminigun[*]
        lea eax, [esp + 0x2B0]
        call sub_69586C
        mov edx, 0x7A7764
        mov ebx, eax
        lea eax, [esp + 0xD0]
        call sub_677C00
        mov edx, 0x6D6211   // force
        call sub_696058
        test eax, eax
        setne bl
        xor edx, edx
        lea eax, [esp + 0xD0]
        call sub_6959C9
        lea eax, [esp + 0x2B0]
        xor edx, edx
        call sub_6959C9
        test bl, bl
        jne go_to_all

        mov ebx, weaponsmissilesandmines_key   // WEAPONSMISSILESANDMINES
        mov edx, modesetup_section  // gametext/modesetup.txt
        mov eax, ds: [0x7E3110]
        call sub_66F410
        mov ebx, -1
        mov edx, eax
        lea eax, [esp + 0x160]
        call sub_69586C
        mov edx, eax
        mov eax, 0x7A7B48
        call sub_695F1D
        lea eax, [esp + 0x160]
        jmp loc_565A84

    go_to_all:
        mov ebx, weaponsall_key   // WEAPONSALL
        mov edx, modesetup_section  // gametext/modesetup.txt
        mov eax, ds: [0x7E3110]
        call sub_66F410
        mov ebx, -1
        mov edx, eax
        lea eax, [esp + 0x160]
        call sub_69586C
        mov edx, eax
        mov eax, 0x7A7B48
        call sub_695F1D
        lea eax, [esp + 0x160]
        jmp loc_565A84

    go_to_missdoublemines:
        xor edx, edx
        call sub_6959C9
        mov ebx, -1
        mov edx, 0x6D6276   // forcemissile[*]
        lea eax, [esp + 0x2B0]
        call sub_69586C
        mov edx, 0x7A7764
        mov ebx, eax
        lea eax, [esp + 0xD0]
        call sub_677C00
        mov edx, 0x6D626F   // double
        call sub_696058
        test eax, eax
        setne bl
        xor edx, edx
        lea eax, [esp + 0xD0]
        call sub_6959C9
        lea eax, [esp + 0x2B0]
        xor edx, edx
        call sub_6959C9
        test bl, bl
        je go_to_mines

        xor edx, edx
        call sub_6959C9
        mov ebx, -1
        mov edx, 0x6D6217   // forceminigun[*]
        lea eax, [esp + 0x2B0]
        call sub_69586C
        mov edx, 0x7A7764
        mov ebx, eax
        lea eax, [esp + 0xD0]
        call sub_677C00
        mov edx, 0x6D6211   // force
        call sub_696058
        test eax, eax
        setne bl
        xor edx, edx
        lea eax, [esp + 0xD0]
        call sub_6959C9
        lea eax, [esp + 0x2B0]
        xor edx, edx
        call sub_6959C9
        test bl, bl
        jne go_to_all2x

        mov ebx, weaponsmissiles2xandmines_key   // WEAPONSMISSILES2XANDMINES
        mov edx, modesetup_section  // gametext/modesetup.txt
        mov eax, ds: [0x7E3110]
        call sub_66F410
        mov ebx, -1
        mov edx, eax
        lea eax, [esp + 0x160]
        call sub_69586C
        mov edx, eax
        mov eax, 0x7A7B48
        call sub_695F1D
        lea eax, [esp + 0x160]
        jmp loc_565A84

    go_to_all2x:
        mov ebx, weaponsall2x_key   // WEAPONSAll2X
        mov edx, modesetup_section  // gametext/modesetup.txt
        mov eax, ds: [0x7E3110]
        call sub_66F410
        mov ebx, -1
        mov edx, eax
        lea eax, [esp + 0x160]
        call sub_69586C
        mov edx, eax
        mov eax, 0x7A7B48
        call sub_695F1D
        lea eax, [esp + 0x160]
        jmp loc_565A84

    go_to_mines:
        mov ebx, weaponsonlymines_key   // WEAPONSONLYMINES
        mov edx, modesetup_section  // gametext/modesetup.txt
        mov eax, ds: [0x7E3110]
        call sub_66F410
        mov ebx, -1
        mov edx, eax
        lea eax, [esp + 0x160]
        call sub_69586C
        mov edx, eax
        mov eax, 0x7A7B48
        call sub_695F1D
        lea eax, [esp + 0x160]
        jmp loc_565A84

    go_to_minigun:
        push 0x56598B
        retn

    loc_565A84:
        push 0x565A84
        retn

    sub_695F1D:
        push 0x695F1D
        retn

    sub_66F410:
        push 0x66F410
        retn

    sub_6959C9:
        push 0x6959C9
        retn

    sub_696058:
        push 0x696058
        retn

    sub_677C00:
        push 0x677C00
        retn

    sub_69586C:
        push 0x69586C
        retn
    }
}

void __declspec(naked) a_MineCapacity()
{
    __asm
    {
        mov [esi + 0x6840], edx
        mov [esi + 0x7318], edx

        jmp loc_4649BF

    loc_4649BF:
        push 0x4649BF
        retn
    }
}

const char* mine_p3dmodel = "mine.p3d";
const char* mine_class = "MINEOBJECT";
const char* mine_objname_base = "mineobject_";
std::string mine_objname;
float mine_reload_time = 3.f;
const char* minedrop_sound = "weapons/minedrop.wav";
float mine_obj_mass = 30.f;

std::string generateRandomString(int length)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 25);

    std::string result;
    for (int i = 0; i < length; ++i)
    {
        result += 'a' + dis(gen);
    }
    return result;
}

void UpdateMineName()
{
    mine_objname = mine_objname_base + generateRandomString(4);
}

int new_mine;

void __declspec(naked) a_MineFunc()
{
    __asm
    {
        test dword ptr [eax + 0x6EBC], 0x7FFFFFFF
        je skip2
        cmp dword ptr [eax + 0x7318], 0
        je skip2
        cmp byte ptr [eax + 0x6837], 0
        je skip2

        mov esi, eax

        call MainFunc

    skip2:
        ret

    MainFunc:
        push ebx
        push ecx
        push esi
        push edi
        sub esp,0x200

        call UpdateMineName

        mov dword ptr [esi + 0x4FFC], 0

        mov eax, esi
        call sub_4514F0
        fcomp dword ptr ds: [0x6E3FAE]
        fnstsw ax
        sahf
        jb skip

        fld dword ptr [esi + 0x5000]
        fcomp dword ptr [mine_reload_time] 
        fstsw ax
        sahf    
        jb skip  

        mov dword ptr [esi + 0x4FFC], 1

    skip:
        cmp dword ptr [esi + 0x4FFC], 1
        jne end2

        mov [esp + 0x80], esi
        lea edx, mine_objname
        mov eax, 0x7DE710
        call sub_639C80
        test al, al
        jz truecond
        jmp end

    truecond:
        mov eax, 0x5000
        call sub_6958F9
        mov esi,eax
        lea edx, mine_objname
        mov ecx,edx
        push 0x3A
        push 0x0
        push mine_obj_mass
        mov ebx,-1
        push 1  // 1 - METAL
        mov edx,mine_p3dmodel
        lea eax,[esp+0x20]
        call sub_69586C
        mov ebx,-1
        push eax
        mov edx, 0x6B5465
        lea eax,[esp+0x14]
        call sub_69586C
        mov ebx,-1
        mov edi,eax
        mov edx,ecx
        lea eax,[esp+0x34]
        call sub_69586C
        mov ecx,edi
        mov edx,eax
        xor ebx,ebx
        mov eax,esi
        call sub_4D3DC0

        mov new_mine, eax   // debug

        mov ecx,eax
        xor edx,edx
        lea eax,[esp+0x20]
        call sub_6959C9
        mov eax,esp
        xor edx,edx
        call sub_6959C9
        lea eax,[esp+0x10]
        xor edx,edx
        call sub_6959C9

        lea eax,[ecx+0x4828]
        call sub_634220
        add eax,0xC
        call sub_5F81A0
        add eax,0x44
        call sub_5F81A0
        lea esi,[eax-0x4878]

        mov eax,esi
        mov edx, mine_class
        call sub_5FBAD0
        mov edx,1
        mov eax,esi
        call sub_4D73F0
        mov edx,1
        mov eax,esi
        call sub_4B41F0
        mov edx,1
        mov eax,esi
        call sub_4D7620

        mov ecx, [esp + 0x80]
        mov [eax + 0x5000], ecx

        mov ecx, eax
        mov esi, [esp + 0x80]
        mov eax,[esi+0x66AC]
        mov [esp+0x148],eax
        mov eax,[esi+0x66B0]
        mov [esp+0x14C],eax
        mov eax,[esi+0x66B4]
        mov [esp+0x150],eax
        mov ebx, esi
        mov edx, esi
        mov eax, esi
        call sub_604EF0
        mov esi, eax
        mov eax, edx
        call sub_604F10

        lea edx,[esp+0x148]
        mov ebx,eax
        call sub_5F8D70
        fld dword ptr [esp+0x148]
        fadd dword ptr [esi]
        fld dword ptr [esp+0x14C]
        fxch st(1)
        fstp dword ptr [esp+0x148]
        fadd dword ptr [esi+0x4]
        fld dword ptr [esp+0x150]
        fxch st(1)
        fstp dword ptr [esp+0x14C]
        fadd dword ptr [esi+0x8]
        fstp dword ptr [esp+0x150]
        mov esi,[ecx+0xD4]
        lea edx,[esp+0x148]
        mov eax,ecx
        call dword ptr [esi+0xC]
        mov esi,[ecx+0xD4]
        mov edx,ebx
        mov eax,ecx
        call dword ptr [esi+0x28]

        jmp end

    end:
        mov esi, [esp + 0x80]

        push 00
        push 00
        push 0xFFFFFFFF
        mov eax,[esi+0xCC0]
        push 00
        lea edx,[eax+0x6C]
        mov ebx,minedrop_sound
        push edx
        add eax,0x4
        xor ecx,ecx
        push eax
        mov edx,0x3
        mov eax,ds: [0x7DF0AC]
        call sub_658000
        xor al,al

        cmp dword ptr [esi + 0x7318], 0
        jne dec_mine_ammo
        jmp end2

    dec_mine_ammo:
        dec [esi + 0x7318]

    end2:
        mov eax, ds: [0x7CD0E0]
        cmp eax, 0
        je end3
        cmp byte ptr [eax + 0x4], 0
        je end3
        mov dword ptr [esi + 0x4FFC], 0
        mov dword ptr [esi + 0x5000], 0

    end3:
        add esp, 0x200
        pop edi
        pop esi
        pop ecx
        pop ebx
        retn

    sub_4514F0:
        push 0x4514F0
        retn

    sub_658000:
        push 0x658000
        retn

    sub_4746F0:
        push 0x4746F0
        retn

    sub_5F8D70:
        push 0x5F8D70
        retn

    sub_604F10:
        push 0x604F10
        retn

    sub_604EF0:
        push 0x604EF0
        retn

    sub_4DAA00:
        push 0x4DAA00
        retn

    sub_604C70:
        push 0x604C70
        retn

    sub_4D97E0:
        push 0x4D97E0
        retn

    sub_604C60:
        push 0x604C60
        retn

    sub_639C80:
        push 0x639C80
        retn

    sub_6958F9:
        push 0x6958F9
        retn

    sub_5F81A0:
        push 0x5F81A0
        retn

    sub_634220:
        push 0x634220
        retn

    sub_5FBAD0:
        push 0x5FBAD0
        retn

    sub_4D73F0:
        push 0x4D73F0
        retn

    sub_4B41F0:
        push 0x4B41F0
        retn

    sub_4D7620:
        push 0x4D7620
        retn

    sub_4D3DC0:
        push 0x4D3DC0
        retn

    sub_69586C:
        push 0x69586C
        retn

    sub_6959C9:
        push 0x6959C9
        retn
    }
}

void __declspec(naked) a_MineDropTimer()
{
    __asm
    {
        cmp dword ptr [eax + 0x4FFC], 0
        je truecond

        mov dword ptr [eax + 0x5000], 0

        jmp end

    truecond:
        fld dword ptr [eax + 0x5000]
        fadd dword ptr [ebp + 0x1C]
        fstp dword ptr [eax + 0x5000]

    end:
        test ecx, 0x7FFFFFFF
        jmp loc_46532E

    loc_46532E:
        push 0x46532E
        retn
    }
}

void __declspec(naked) a_DeleteAllMines()
{
    __asm
    {
        mov edx, mine_class
        lea eax, [esp + 0x110]
        call sub_696058
        test eax, eax
        je end

        jmp loc_63C9FC

    end:
        mov edx, 0x6F2EF9
        jmp loc_63C9EC

    sub_696058:
        push 0x696058
        retn

    loc_63C9FC:
        push 0x63C9FC
        retn

    loc_63C9EC:
        push 0x63C9EC
        retn
    }
}

void __declspec(naked) a_ResetCondition()
{
    __asm
    {
        mov dword ptr [eax + 0x944], 0
        mov dword ptr [eax + 0x4FFC], 0
        mov dword ptr [eax + 0x5000], 0

        jmp loc_44BED1

    loc_44BED1:
        push 0x44BED1
        retn
    }
}

int mines_hud_color;
int mines_hud_alpha;
const char* mines_hud_texture = "misc/mines.tga";

void __declspec(naked) a_MinesHUD()
{
    __asm
    {
        mov eax, [esp + 0xA8]
        cmp byte ptr [eax + 0x6837], 1  // has mines?
        jne end2

        mov eax,[esp+0xA8]
        call sub_4514F0
        fcomp dword ptr ds: [0x6E3FAE]
        fnstsw ax
        sahf 
        jae skip

        mov eax,[esp+0xA8]
        call sub_4514F0
        fmul dword ptr ds: [0x6E3FB2]
        mov eax,[esp+0xA8]
        fstp qword ptr [esp+0x44]
        call sub_4514F0
        fmul dword ptr ds: [0x6E3FB2]
        sub esp,0x8
        fstp qword ptr [esp]
        call sub_695F4D
        fsubr qword ptr [esp+0x44]
        fcomp qword ptr ds: [0x6E3FBA]
        fnstsw ax
        sahf 
        jae skip
        xor edx,edx

    skip:
        mov dword ptr[mines_hud_alpha], 0
        cmp edx, 0
        je skip4
        mov dword ptr [mines_hud_alpha], 0x3F800000

    skip4:
        mov eax, [esp + 0xA8]
        call sub_4514F0
        fcomp dword ptr ds: [0x6E3FAE]
        fnstsw ax
        sahf
        jb skip2

        mov eax, [esp + 0xA8]
        cmp dword ptr [eax + 0x7318], 0
        je skip2

        fld dword ptr [eax + 0x5000]
        fcomp dword ptr [mine_reload_time] 
        fstsw ax
        sahf    
        jb skip2  
        mov mines_hud_color, 0xFFFFFF
        jmp skip3

    skip2:
        mov mines_hud_color, 0xED1F1F

    skip3:
        mov eax, [esp + 0xA8]
        mov edi, [eax + 0x7318]
        push edi
        push 0x6E362A
        push 0x7CC780
        call sub_696710
        add esp,0xC

        push 0x3F800000
        push 0
        push 0
        push mines_hud_alpha
        push mines_hud_color
        push 0x7CC780
        fld dword ptr [esp+0xA4]
        fadd dword ptr [esp+0xA8]
        sub esp,0x4
        fld dword ptr [esp+0xB4]
        fxch st(1)
        fadd dword ptr ds: [0x6E3F8E]
        fxch st(1)
        fadd dword ptr ds: [0x6E3FC2]
        fxch st(1)
        fstp dword ptr [esp]
        fadd dword ptr [esp+0xB0]
        fsub dword ptr ds: [0x6E3F82]
        sub esp,04
        fstp dword ptr [esp]
        mov ecx, 4
        mov ebx, 0
        mov edx, 0
        mov eax, ds: 0x7CF700
        push 0x40A00000
        call sub_5F2160

        mov edx, mines_hud_texture
        mov eax, ds: 0x7CF700
        push 0
        call sub_5E4D20

        push mines_hud_color
        xor esi,esi
        mov [esp+0x48],edx
        mov [esp+0x4C],esi
        push 01
        fild qword ptr [esp+0x4C]
        fstp dword ptr [esp+0x54]
        push mines_hud_alpha
        fld dword ptr [esp+0x9C]
        fld st(0)
        push 0x3F800000
        mov eax,ds: [0x7CF700]
        push 0x3F800000
        xor ebx,ebx
        push 00
        fadd dword ptr [esp+0x9C]
        push 0
        fld dword ptr [esp+0xA8]
        fxch st(1)
        fadd st(0),st(1)
        sub esp,0x4
        fld dword ptr [esp+0xB8]
        fsub dword ptr ds : [0x6E3F82]
        fadd dword ptr [esp+0xA8]
        fxch st(1)
        fstp dword ptr [esp]
        fadd dword ptr [esp+0xB4]
        sub esp,0x4
        fld dword ptr [esp+0xBC]
        fsub dword ptr ds : [0x6E3F82]
        fxch st(3)
        faddp st(2),st(0)
        fstp dword ptr [esp]
        fstp dword ptr [esp+0x74]
        push [esp+0x74]
        fadd dword ptr [esp+0xBC]
        sub esp,0x4
        mov edx, mines_hud_texture
        fstp dword ptr [esp]
        call sub_60F950
        jmp end

    end2:
        mov edx, mines_hud_texture
        mov eax, ds: 0x7CF700
        push 0
        call sub_5E4D20

        push 0xFFFFFF
        push 01
        push 0x3EB33333
        fld dword ptr [esp+0x9C]
        fld st(0)
        push 0x3F800000
        mov eax,ds: [0x7CF700]
        push 0x3F800000
        xor ebx,ebx
        push 00
        fadd dword ptr [esp+0x9C]
        push 0
        fld dword ptr [esp+0xA8]
        fxch st(1)
        fadd st(0),st(1)
        sub esp,0x4
        fld dword ptr [esp+0xB8]
        fsub dword ptr ds : [0x6E3F82]
        fadd dword ptr [esp+0xA8]
        fxch st(1)
        fstp dword ptr [esp]
        fadd dword ptr [esp+0xB4]
        sub esp,0x4
        fld dword ptr [esp+0xBC]
        fsub dword ptr ds : [0x6E3F82]
        fxch st(3)
        faddp st(2),st(0)
        fstp dword ptr [esp]
        fstp dword ptr [esp+0x74]
        push [esp+0x74]
        fadd dword ptr [esp+0xBC]
        sub esp,0x4
        mov edx, mines_hud_texture
        fstp dword ptr [esp]
        call sub_60F950

    end:
        fld dword ptr [esp+0x94]

        jmp loc_5A9C3A

    sub_5E4D20:
        push 0x5E4D20
        retn

    sub_60F950:
        push 0x60F950
        retn

    sub_695F4D:
        push 0x695F4D
        retn

    sub_4514F0:
        push 0x4514F0
        retn

    sub_5F2160:
        push 0x5F2160
        retn

    sub_696710:
        push 0x696710
        retn

    loc_5A9C3A:
        push 0x5A9C3A
        retn
    }
}

void __declspec(naked) a_MinesAI()
{
    __asm
    {
        mov eax, ecx
        call sub_40A620

        cmp byte ptr [ecx + 0xB892], 0
        jmp loc_4033AD

    loc_4033AD:
        push 0x4033AD
        retn

    sub_40A620:
        push 0x40A620
        retn
    }
}

float mine_activate_time = 0.1f;

float mine_life_time = 30.f;

void __declspec(naked) a_MinesHandler()
{
    __asm
    {
        lea eax, [esp + 0x20]
        call sub_69598E

        mov eax, edi
        call sub_5FB9F0

        mov edx, eax
        lea eax, [esp + 0x20]
        call sub_695A15

        mov edx, mine_class
        lea eax, [esp + 0x20]
        call sub_696058
        test eax, eax
        je end

        mov eax, edi
        fld dword ptr [eax + 0x88]
        fcomp dword ptr [mine_activate_time]
        fstsw ax
        sahf    
        jb end

        mov eax, edi
        mov byte ptr [eax + 0x940], 6   // 6 - EXPLOSIVE

        cmp byte ptr [eax + 0x959], 0
        je end

        mov eax, edi
        call sub_5FBC60

        mov esi, ds: [0x7DE710]
        mov edx, eax
        mov ebx, 0
        mov eax, esi
        call sub_637800

        jmp end

    end:
        mov edx, mine_class
        lea eax, [esp + 0x20]
        call sub_696058
        test eax, eax
        je end2

        mov eax, edi
        fld dword ptr [eax + 0x88]
        fcomp dword ptr [mine_life_time]
        fstsw ax
        sahf    
        jb end2

        mov eax, edi
        call sub_5FBC60

        mov esi, ds: [0x7DE710]
        mov edx, eax
        mov ebx, 0
        mov eax, esi
        call sub_637800

    end2:
        mov eax, edi
        fld dword ptr [edi + 0x78]
        fcomp dword ptr [eax + 0x92C]
        jmp loc_6015B9

    sub_637800:
        push 0x637800
        retn

    sub_5FBC60:
        push 0x5FBC60
        retn

    sub_69598E:
        push 0x69598E
        retn

    sub_695A15:
        push 0x695A15
        retn

    sub_696058:
        push 0x696058
        retn

    sub_5FB9F0:
        push 0x5FB9F0
        retn

    loc_6015B9:
        push 0x6015B9
        retn
    }
}
/*
void __declspec(naked) a_MinesHitInfo()
{
    __asm
    {
        // eax - mine
        // eax + 0x8080 - car dropped the mine
        // esi - car hitted by mine

        call sub_4D7230

        mov ebx, eax

        lea eax, [esp + 0x20]
        call sub_69598E

        mov eax, ebx
        call sub_5FB9F0

        mov edx, eax
        lea eax, [esp + 0x20]
        call sub_695A15

        mov edx, mine_class
        lea eax, [esp + 0x20]
        call sub_696058
        test eax, eax
        je end

        mov eax, [ebx + 0x8080]
        mov mine_owner, eax
        mov eax, ebx
        cmp dword ptr mine_owner, esi   // skip if hitted by own mine
        je end

        mov ebx, ds: [0x7DEA20]
        mov ebx, [ebx + 0x10]
        mov ebx, [ebx + 0xC]
        mov ebx, [ebx]
        cmp dword ptr mine_owner, ebx    // check if POV is from mine dropper
        jne end

        mov show_info, 1

    end:
        jmp loc_4D17F1

    sub_4D7230:
        push 0x4D7230
        retn

    sub_69598E:
        push 0x69598E
        retn

    sub_695A15:
        push 0x695A15
        retn

    sub_696058:
        push 0x696058
        retn

    sub_5FB9F0:
        push 0x5FB9F0
        retn

    loc_6015B9:
        push 0x6015B9
        retn

    loc_4D17F1:
        push 0x4D17F1
        retn
    }
}

int show_info2;

void __declspec(naked) a_MinesGetPlayerHP()
{
    __asm
    {
        mov [esp + 0x198], eax

        cmp show_info, 1
        je loc_4D0838

        cmp show_info2, 1
        je loc_4D0838

        fld dword ptr [eax + 0x6EBC]
        fstp dword ptr [hp_before]

        jmp loc_4D0838

    loc_4D0838:
        push 0x4D0838
        retn
    }
}

int curcar;

float hp_before_sub = 3.f;

void __declspec(naked) a_MinesShowHitInfo()
{
    __asm
    {
        // eax - car dropped the mine
        // ecx -  car hitted by mine

        cmp show_info, 0
        je end

        mov eax, [ebp - 0x10]

        cmp eax, mine_owner
        je end2
        mov ecx, eax

    end2:
        mov show_info2, 1

        mov eax, mine_owner
        mov byte ptr [eax + 0x9790], 7   // 7 - Mine Hit

        fld dword ptr [hp_before]
        fsub dword ptr [hp_before_sub]
        fld dword ptr [ecx + 0x6EBC]
        fcomip st(0), st(1)
        jnb end
        fstp st(0)

        fld dword ptr [hp_before]
        fsub dword ptr [ecx + 0x6EBC]
        fstp dword ptr [eax + 0x978C]

        mov show_info, 0

    end:
        mov esp, ebp
        pop ebp
        pop edi
        pop esi
        pop edx
        pop ecx
        pop ebx
        ret
    }
}
*/
float mine_damage = 50.f;
float mine_impulse = 7.5f;
float mine_ai_aggr = 20.f;

int mine_ptr;

int show_info;

void __declspec(naked) a_MinesExplosion()
{
    __asm
    {
        lea eax, [esp + 0x20]
        call sub_69598E

        mov eax, mine_ptr
        call sub_5FB9F0

        mov edx, eax
        lea eax, [esp + 0x20]
        call sub_695A15

        mov edx, mine_class
        lea eax, [esp + 0x20]
        call sub_696058
        test eax, eax
        je end

        fld dword ptr [esp]
        fmul dword ptr [mine_damage]
        fstp dword ptr [esp]
            
        mov eax, esi
        mov eax, [eax + 0xCC0]

        fld dword ptr [mine_impulse]
        fstp dword ptr [eax + 0x78]

        fld dword ptr [mine_impulse]
        fstp dword ptr [eax + 0x80]

        mov eax, mine_ptr
        cmp dword ptr [eax + 0x5000], esi   // add aggression when hits player's mine
        je end

        mov eax, esi
        fld dword ptr [eax + 0xB800]
        fadd dword ptr [mine_ai_aggr]
        fstp dword ptr [eax + 0xB800]

        mov show_info, 1

        jmp end

    end:
        mov eax, [esi+0x26D6]
        jmp loc_4D162A

    sub_4D7060:
        push 0x4D7060
        retn

    sub_4DA5B0:
        push 0x4DA5B0
        retn

    sub_69598E:
        push 0x69598E
        retn

    sub_695A15:
        push 0x695A15
        retn

    sub_696058:
        push 0x696058
        retn

    sub_5FB9F0:
        push 0x5FB9F0
        retn

    loc_4D162A:
        push 0x4D162A
        retn
    }
}

int restore1;
int restore2;
int restore3;
int restore4;
int restore5;
int restore6;
int restore7;
int restore8;

int player_ptr;
int victim_ptr;
float victim_hp;

void __declspec(naked) a_MinesShowInfo()
{
    __asm
    {
        call sub_5BF170

        lea eax, [esp + 0x20]
        call sub_69598E

        mov eax, mine_ptr
        call sub_5FB9F0

        mov edx, eax
        lea eax, [esp + 0x20]
        call sub_695A15

        mov edx, mine_class
        lea eax, [esp + 0x20]
        call sub_696058
        test eax, eax
        je end

        mov show_info, 1

        mov ecx, mine_ptr
        mov ecx, [ecx + 0x5000]
        mov player_ptr, ecx
        mov victim_ptr, esi
        fld dword ptr [esi + 0x6EBC]
        fstp dword ptr [victim_hp]

    end:
        jmp loc_4D1652

    loc_4D1652:
        push 0x4D1652
        retn

    sub_5BF170:
        push 0x5BF170
        retn

    sub_4D7060:
        push 0x4D7060
        retn

    sub_4DA5B0:
        push 0x4DA5B0
        retn

    sub_69598E:
        push 0x69598E
        retn

    sub_695A15:
        push 0x695A15
        retn

    sub_696058:
        push 0x696058
        retn

    sub_5FB9F0:
        push 0x5FB9F0
        retn
    }
}

void __declspec(naked) a_MinesExplosion2()
{
    __asm
    {
        mov eax, [esi + eax + 0x18DC]
        mov mine_ptr, eax

        jmp loc_4D0AA5

    loc_4D0AA5:
        push 0x4D0AA5
        retn
    }
}

float hp_fin;

void __declspec(naked) a_MinesShowInfo2()
{
    __asm
    {
        //cmp dword ptr ds: [0x7CD0E0], 0
        //jne end2
        cmp byte ptr [show_info], 0
        je end

        mov restore1, eax
        mov restore2, ebx
        mov restore3, ecx
        mov restore4, edx
        mov restore5, esi
        mov restore6, edi
        mov restore7, ebp
        mov restore8, esp

        mov eax, player_ptr
        mov edx, victim_ptr
        
        cmp eax, edx
        je end2

        cmp byte ptr [edx + 0x5008], 2
        je skip
        mov [edx + 0x5004], eax
        inc [edx + 0x5008]
        jmp skip2

    skip:
        mov [edx + 0x5004], 0
        mov [edx + 0x5008], 0

    skip2:
        fld dword ptr [victim_hp]
        fsub dword ptr [edx + 0x6EBC]
        fstp dword ptr [hp_fin]

        fld hp_fin
        fld victim_hp
        fcomip st(0), st(1)
        fstp st(0)
        je wreck_true
        push 0
        jmp wreck_end

    wreck_true:
        push 1

    wreck_end:
        push dword ptr [hp_fin]
        call dword ptr ds: [0x78A7F0]

        mov eax, restore1
        mov ebx, restore2
        mov ecx, restore3
        mov edx, restore4
        mov esi, restore5
        mov edi, restore6
        mov ebp, restore7
        mov esp, restore8

    end2:
        mov show_info, 0
        jmp end

    end:
        fld dword ptr [ebp + 0x6EBC]
        jmp loc_5065D3

    loc_5065D3:
        push 0x5065D3
        retn
    }
}

void __declspec(naked) a_MinesEventHandler()
{
    __asm
    {
        push ebx
        push ecx
        push esi
        sub esp, 0x10
        mov esi, eax
        mov ebx, edx
        mov eax, ds: [0x78D5F0]
        cmp byte ptr [eax + 0x80], 0x3
        je loc_108441

    loc_508438:
        add esp, 0x10
        pop esi
        pop ecx
        pop ebx
        ret 0x8

    loc_108441:
        mov edx, 0x6C7FC9   // GAMECAROBJECT
        mov eax, ebx
        call sub_5FBA90
        test al, al
        je loc_508438
        mov eax, ebx
        call sub_4513D0
        test al, al
        je loc_508438
        //mov eax, esp
        //call sub_69598E
        mov eax, esi
        call sub_5061B0
        mov ecx, [eax + 0x30]
        inc ecx
        mov edx, ds: [0x78D5F0]
        mov [eax + 0x30], ecx
        cmp byte ptr [edx], 0
        jne loc_5084AF
        cmp byte ptr [esp + 0x24], 0
        jne loc_5084AF
        fld dword ptr [eax + 0x1DFC]
        mov dword ptr [eax + 0x1DF8], 0
        fadd dword ptr [esp + 0x20]
        mov dl, [eax + 0x1E00]
        fstp dword ptr [eax + 0x1DFC]
        cmp [ebx + 0x5004], esi
        je loc_5084DF
        mov byte ptr [eax + 0x1E00], 7

    loc_5084AF:
        cmp byte ptr [esp + 0x24], 0
        je loc_5084CD
        //cmp byte ptr ds: [0x70DA98], 1
        //jne loc_5084CD
        mov ecx, 1
        mov eax, esi
        xor edx, edx
        call sub_508580

    loc_5084CD:
        //mov eax, esp
        //xor edx, edx
        //call sub_6959C9
        add esp, 0x10
        pop esi
        pop ecx
        pop ebx
        ret 0x8

    loc_5084DF:
        cmp [ebx + 0x5008], 2
        je cont
        mov byte ptr [eax + 0x1E00], 7
        jmp loc_5084AF

    cont:
        mov byte ptr [eax + 0x1E00], 8
        mov [ebx + 0x5008], 0
        mov [ebx + 0x5004], 0
        jmp loc_5084AF

    sub_6959C9:
        push 0x6959C9
        retn

    sub_508580:
        push 0x508580
        retn

    sub_4513D0:
        push 0x4513D0
        retn

    sub_5FBA90:
        push 0x5FBA90
        retn

    sub_69598E:
        push 0x69598E
        retn

    sub_5061B0:
        push 0x5061B0
        retn
    }
}

void Mines()
{
    injector::MakeJMP(0x53393C, a_MinesShop, true);
    injector::MakeJMP(0x5830C5, a_MinesEventSetup, true);
    injector::MakeNOP(0x5830DB, 2, true);
    injector::MakeNOP(0x5830EB, 7, true);
    injector::MakeJMP(0x56713F, a_MinesEventInfoMP, true);
    injector::MakeJMP(0x4649B9, a_MineCapacity, true);
    injector::MakeJNE(0x43E190, a_MineFunc, true);
    injector::MakeJMP(0x465328, a_MineDropTimer, true);
    injector::MakeJMP(0x63C9E7, a_DeleteAllMines, true);
    injector::MakeJMP(0x44BEC7, a_ResetCondition, true);
    injector::MakeJMP(0x5A9C33, a_MinesHUD, true);
    injector::MakeJMP(0x4033A6, a_MinesAI, true);
    injector::MakeJMP(0x6015B0, a_MinesHandler, true);
    injector::MakeJMP(0x4D1624, a_MinesExplosion, true);
    injector::MakeJMP(0x4D0A9E, a_MinesExplosion2, true);
    injector::MakeJMP(0x4D164D, a_MinesShowInfo, true);
    injector::MakeJMP(0x5065CD, a_MinesShowInfo2, true);
    injector::MakeJMP(0x5084F0, a_MinesEventHandler, true);
    injector::WriteMemory<BYTE>(0x43E1A9, 0xC3, true);
    injector::WriteMemory<BYTE>(0x50DC67, 6, true); // HUD message - Mine Hit
    injector::WriteMemory<BYTE>(0x50DCD4, 6, true); // HUD message - Double Mine Hit
}


DWORD WINAPI MainTHREAD(LPVOID)
{
    Mines();
    return 0;
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		if (*(DWORD*)0x4000A8 == 0x29BB90)	// Checking the entry point of 1.2 executable
		{
			CreateThread(0, 0, MainTHREAD, 0, 0, 0);
		}
		else
			return FALSE;
	}

	return TRUE;
}
