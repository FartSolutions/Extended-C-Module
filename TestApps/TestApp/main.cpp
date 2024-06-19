#include <crtdbg.h>
#include <ecm/ecm.hpp>
#include <ecm/ecm_math.hpp>
#include <ecm/algorithm/random.h>
#include <ecm/ecm_window.hpp>
#include <ecm/ecm_opengl.hpp>

#pragma warning(disable : 4996)

namespace ec = ecm::console;

#include <thread>
#include <mutex>

std::atomic<bool> thread1_ready{ false };
std::atomic<bool> thread2_ready{ false };

void test_Threading()
{
	std::thread thread1{
		[]() {
			int i{ 0 };
			while (i < 10)
			{
				ec::Write("Dies ist eine Testnachricht des Threads 1.");
				ec::WriteLine(" Dies ist Teil 2.");
				//_sleep(95);
				i++;
			}
			thread1_ready = true;
		}
	};
	
	std::thread thread2{
		[]() {
			int i{ 0 };
			while (i < 10)
			{
				ec::Write("Dies ist eine Testnachricht des Threads 2.");
				ec::WriteLine(" Dies ist Teil 2.");
				//_sleep(105);
				i++;
			}
			thread2_ready = true;
		}
	};
	
	thread1.detach();
	thread2.detach();

	bool succeeded{ false };
	while (!succeeded)
	{
		_sleep(100);
		if (thread1_ready && thread2_ready) succeeded = true;
	}
}

void test_ConsoleSystem()
{
	ec::WriteLine("%sHello World! Black",			ec::ANSI::BG_Black);
	ec::WriteLine("%sHello World! Red",				ec::ANSI::BG_Red);
	ec::WriteLine("%sHello World! Green",			ec::ANSI::BG_Green);
	ec::WriteLine("%sHello World! Yellow",			ec::ANSI::BG_Yellow);
	ec::WriteLine("%sHello World! Blue",			ec::ANSI::BG_Blue);
	ec::WriteLine("%sHello World! Magenta",			ec::ANSI::BG_Magenta);
	ec::WriteLine("%sHello World! Cyan",			ec::ANSI::BG_Cyan);
	ec::WriteLine("%sHello World! LightGray",		ec::ANSI::BG_LightGray);
	ec::WriteLine("%sHello World! Gray",			ec::ANSI::BG_DarkGray);
	ec::WriteLine("%sHello World! LightRed",		ec::ANSI::BG_LightRed);
	ec::WriteLine("%sHello World! LightGreen",		ec::ANSI::BG_LightGreen);
	ec::WriteLine("%sHello World! LightYellow",		ec::ANSI::BG_Yellow);
	ec::WriteLine("%sHello World! LightBlue",		ec::ANSI::BG_LightBlue);
	ec::WriteLine("%sHello World! LightMagenta",	ec::ANSI::BG_LightMagenta);
	ec::WriteLine("%sHello World! LightCyan",		ec::ANSI::BG_LightCyan);
	ec::WriteLine("%sHello World! White,%s",		ec::ANSI::BG_White, ec::ANSI::Reset);
	
	ec::WriteLine("%sHello World! Black",			ec::ANSI::FG_Black);
	ec::WriteLine("%sHello World! Red",				ec::ANSI::FG_Red);
	ec::WriteLine("%sHello World! Green",			ec::ANSI::FG_Green);
	ec::WriteLine("%sHello World! Yellow",			ec::ANSI::FG_Yellow);
	ec::WriteLine("%sHello World! Blue",			ec::ANSI::FG_Blue);
	ec::WriteLine("%sHello World! Magenta",			ec::ANSI::FG_Magenta);
	ec::WriteLine("%sHello World! Cyan",			ec::ANSI::FG_Cyan);
	ec::WriteLine("%sHello World! LightGray",		ec::ANSI::FG_LightGray);
	ec::WriteLine("%sHello World! Gray",			ec::ANSI::FG_DarkGray);
	ec::WriteLine("%sHello World! LightRed",		ec::ANSI::FG_LightRed);
	ec::WriteLine("%sHello World! LightGreen",		ec::ANSI::FG_LightGreen);
	ec::WriteLine("%sHello World! LightYellow",		ec::ANSI::FG_Yellow);
	ec::WriteLine("%sHello World! LightBlue",		ec::ANSI::FG_LightBlue);
	ec::WriteLine("%sHello World! LightMagenta",	ec::ANSI::FG_LightMagenta);
	ec::WriteLine("%sHello World! LightCyan",		ec::ANSI::FG_LightCyan);
	ec::WriteLine("%sHello World! White%s",			ec::ANSI::FG_White, ec::ANSI::Reset);

	ec::WriteLine("%sHello World! Bold%s",			ec::ANSI::Bold, ec::ANSI::Reset);
	ec::WriteLine("%sHello World! Semi-Transparent%s", ec::ANSI::SemiTransparent, ec::ANSI::Reset);
	ec::WriteLine("%sHello World! Italic%s",		ec::ANSI::Italic, ec::ANSI::Reset);
	ec::WriteLine("%sHello World! Underlined%s",	ec::ANSI::Underlined, ec::ANSI::Reset);
	ec::WriteLine("%sHello World! Blinking%s",		ec::ANSI::SlowBlink, ec::ANSI::Reset);
	ec::WriteLine("%sHello World! Rapid Blink%s",	ec::ANSI::RapidBlink, ec::ANSI::Reset);
	ec::WriteLine("%sHello World! Swaped%s",		ec::ANSI::Swapped, ec::ANSI::Reset);
	ec::WriteLine("%sHello World! Invisible%s",		ec::ANSI::Invisible, ec::ANSI::Reset);
	ec::WriteLine();
}

void test_WindowSystem()
{
	ecm::GraphicsAPI gApi{ ecm::GRAPHICSAPI_OPENGL };

	ecm::Window window = ecm::CreateWindow("Test window", { 800, 600 },
		ecm::WINDOWFLAG_RESIZABLE, ecm::WINDOWMODE_SHOWN, gApi);

	ecm::ContextBase* context = nullptr;
	if (gApi == ecm::GRAPHICSAPI_SDLRENDERER) context = new ecm::SDLRendererContext();
	else if (gApi == ecm::GRAPHICSAPI_OPENGL) context = new ecm::gl::OpenGLContext();
	else context = new ecm::SDLRendererContext();

	context->Initialize(window);
	context->SetColor(ecm::ColorF(0x1A304Cff));
	context->SetVSyncMode(ecm::VSYNC_ENABLED);

	while (!window.IsClosed())
	{
		ecm::Event e{};
		while (ecm::PollEvent(e));

		context->ClearBuffers();
		context->SwapBuffers();
	}

	context->Shutdown();
	delete context;
	ecm::DestroyWindow(window);
}

template<typename _Ty>
void test_vector(_Ty v1, _Ty v2)
{
	_Ty test_vec2d3{ v1 + v2 };
	_Ty test_vec2d4{ v1 - v2 };
	_Ty test_vec2d5{ v1 * v2 };
	_Ty test_vec2d6{ v1 / v2 };

	test_vec2d3 += v1;
	test_vec2d4 -= v2;
	test_vec2d5 *= test_vec2d3;
	test_vec2d6 /= test_vec2d4;

	test_vec2d3 = test_vec2d3 + 50.f;
	test_vec2d4 = test_vec2d4 - 50.f;
	test_vec2d5 = test_vec2d5 * 50.f;
	test_vec2d6 = test_vec2d6 / 50.f;

	test_vec2d3 += 3.f;
	test_vec2d4 -= 3.f;
	test_vec2d5 *= 3.f;
	test_vec2d6 /= 3.f;
}

#pragma comment(lib, "sdl2.lib")
void test_Math()
{
	test_vector<ecm::math::Vector2>({ 720.f, 1280.f }, { 800.f, 600.f });
	test_vector<ecm::math::Vector3>({ 720.f, 1280.f, 1561.f }, { 800.f, 600.f, 654.f });
	test_vector<ecm::math::Vector4>({ 720.f, 1280.f, 1561.f, 12.f }, { 800.f, 600.f, 654.f, 53.f });

	ecm::math::Matrix4x4 mat1{ 5, 7, 9, 10, 2, 3, 3, 8, 8, 10, 2, 3, 3, 3, 4, 8 };
	ecm::math::Matrix4x4 mat2{ 3, 10, 12, 18, 12, 1, 4, 9, 9, 10, 12, 2, 3, 12, 4, 10 };
	ecm::math::Matrix4x4 matRes = mat1 * mat2;

	if (mat1 == mat1)
	{
		mat1 *= mat1;
		ecm::console::WriteLine("Upps, da passt was nicht!");
	}

	ecm::int8 abs1{ ecm::math::Abs<ecm::int8>(-108) };
	ecm::int16 abs2{ ecm::math::Abs<ecm::int16>(-1286) };
	ecm::int32 abs3{ ecm::math::Abs(-12839566) };
	ecm::int64 abs4{ ecm::math::Abs(-12873565635685) };

	ecm::uint64 fact{ ecm::math::Fact<ecm::uint64>(10) };
	ecm::float128 pow{ ecm::math::Pow(21.4L, 5) };
	std::cout << "My: " << pow << ", SDLs: " << SDL_pow(21.4, 5) << std::endl;
	ecm::float128 fmod{ ecm::math::Fmod(21.4, 54.8) };
	std::cout << "My: " << fmod << ", SDLs: " << SDL_fmod(21.4, 54.8) << std::endl;
}

#undef main
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	test_Threading();
	test_ConsoleSystem();
	test_WindowSystem();
	test_Math();
	
	system("pause");
	return 0;
}
