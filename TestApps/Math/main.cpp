#include <ecm/ecm_math.hpp>
#include <SDL2/SDL.h>
#include <cmath>
#include <chrono>

#pragma comment(lib, "sdl2.lib")

template<typename T1, typename T2>
void test_type(T1 t1, T2 t2)
{
	auto t3 = t1 + t2;
	auto t4 = t1 - t2;
	auto t5 = t1 * t2;
	auto t6 = t1 / t2;

	t3 += t1;
	t4 -= t2;
	t5 *= t1;
	t6 /= t2;

	t3 = t3 + 50.f;
	t4 = t4 - 50;
	t5 = t5 * 50.f;
	t6 = t6 / 50;

	t3 += 3;
	t4 -= 3.f;
	t5 *= 3;
	t6 /= 3.f;

	t3++;
	++t4;
	t5--;
	--t6;
	-t3;
	+t5;

	t1 = t2;
	t2 = t1;
	t1 = T1(t2);
	t2 = T2(t1);

	if ((t3 == t4 || t5 == t5) && (t3 != t4 || t5 != t5)) {
		t3 *= t5;
	}
}

void test_types()
{
	test_type(ecm::math::Vector2(720.f, 1280), ecm::math::Vector2i(800, 600.f));
	test_type(ecm::math::Vector3(720.f, 1280, 1561.f), ecm::math::Vector3i(800, 600.f, 654));
	test_type(ecm::math::Vector4(720.f, 1280, 1561.f, 12), ecm::math::Vector4i(800, 600.f, 654, 53));

	ecm::math::Matrix4x4 mat1(5, 7, 9, 10, 2, 3, 3, 8, 8, 10, 2, 3, 3, 3, 4, 8);
	ecm::math::Matrix4x4i mat2(3, 10, 12, 18, 12, 1, 4, 9, 9, 10, 12, 2, 3, 12, 4, 10);

	test_type(mat1, mat2);

	ecm::math::Rotate(mat1, 4, ecm::math::Vector3(1, 1, 0));
}

void test_sin()
{
	auto start = std::chrono::high_resolution_clock::now();
	for (int i{ 0 }; i < 1000; ++i) {
		for (int deg{ 0 }; deg < 360; deg++) {
			// Deg2Rad
			ecm::float64 rad{ deg * (ecm::math::PI / 180.0) };
			volatile auto resEcm{ ecm::math::Sin(rad) };
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	printf("%i sin operations, time elapsed: %0.80f\n", 1000 * 360, elapsed.count());
}

void test_cos()
{
	auto start = std::chrono::high_resolution_clock::now();
	for (int i{ 0 }; i < 1000; ++i) {
		for (int deg{ 0 }; deg < 360; deg++) {
			// Deg2Rad
			ecm::float64 rad{ deg * (ecm::math::PI / 180.0) };
			volatile auto resEcm{ ecm::math::Cos(rad) };
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	printf("%i cos operations, time elapsed: %0.80f\n", 1000 * 360, elapsed.count());
}

void test_tan()
{
	auto start = std::chrono::high_resolution_clock::now();
	for (int i{ 0 }; i < 1000; ++i) {
		for (int deg{ 0 }; deg < 360; deg++) {
			// Deg2Rad
			ecm::float64 rad{ deg * (ecm::math::PI / 180.0) };
			volatile auto resEcm{ ecm::math::Tan(rad) };
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	printf("%i tan operations, time elapsed: %0.80f\n", 1000 * 360, elapsed.count());
}

void test_basics()
{
	ecm::int8 abs1{ ecm::math::Abs<ecm::int8>(-108) };
	ecm::int16 abs2{ ecm::math::Abs<ecm::int16>(-1286) };
	ecm::int32 abs3{ ecm::math::Abs(-12839566) };
	ecm::int64 abs4{ ecm::math::Abs(-12873565635685) };
	ecm::uint64 fact{ ecm::math::Fact<ecm::uint64>(10) };
	printf("Pow: [ sdl2: %0.80f, ecm: %0.80f ]\n", SDL_pow(21.4, 5), ecm::math::Pow(21.4, 5));
	printf("Fmod: [ sdl2: %0.80f, ecm: %0.80f ]\n", SDL_fmod(21.4, 54.8), ecm::math::Fmod(21.4, 54.8));

	test_sin();
	test_cos();
	test_tan();
}

#undef main
int main()
{
	test_basics();
	test_types();

	system("pause");
	return 0;
}
