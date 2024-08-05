#include <ecm/ecm_math.hpp>
#include <SDL2/SDL.h>
#include <cmath>
#include <chrono>

#pragma comment(lib, "sdl2.lib")

template<typename _Ty>
void test_vector_f(_Ty v1, _Ty v2)
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

template<typename _Ty>
void test_vector_i(_Ty v1, _Ty v2)
{
	_Ty test_vec2d3{ v1 + v2 };
	_Ty test_vec2d4{ v1 - v2 };
	_Ty test_vec2d5{ v1 * v2 };
	_Ty test_vec2d6{ v1 / v2 };

	test_vec2d3 += v1;
	test_vec2d4 -= v2;
	test_vec2d5 *= test_vec2d3;
	test_vec2d6 /= test_vec2d4;

	test_vec2d3 = test_vec2d3 + 50;
	test_vec2d4 = test_vec2d4 - 50;
	test_vec2d5 = test_vec2d5 * 50;
	test_vec2d6 = test_vec2d6 / 50;

	test_vec2d3 += 3;
	test_vec2d4 -= 3;
	test_vec2d5 *= 3;
	test_vec2d6 /= 3;
}

void test_vectors()
{
	test_vector_f<ecm::math::Vector2>({ 720.f, 1280.f }, { 800.f, 600.f });
	test_vector_f<ecm::math::Vector2A>({ 720.f, 1280.f }, { 800.f, 600.f });
	test_vector_i<ecm::math::Vector2i>({ 720, 1280 }, { 800, 600 });
	test_vector_i<ecm::math::Vector2iA>({ 720, 1280 }, { 800, 600 });
	test_vector_f<ecm::math::Vector3>({ 720.f, 1280.f, 1561.f }, { 800.f, 600.f, 654.f });
	test_vector_f<ecm::math::Vector3A>({ 720.f, 1280.f, 1561.f }, { 800.f, 600.f, 654.f });
	test_vector_i<ecm::math::Vector3i>({ 720, 1280, 1561 }, { 800, 600, 654 });
	test_vector_i<ecm::math::Vector3iA>({ 720, 1280, 1561 }, { 800, 600, 654 });
	test_vector_f<ecm::math::Vector4>({ 720.f, 1280.f, 1561.f, 12.f }, { 800.f, 600.f, 654.f, 53.f });
	test_vector_f<ecm::math::Vector4A>({ 720.f, 1280.f, 1561.f, 12.f }, { 800.f, 600.f, 654.f, 53.f });
	test_vector_i<ecm::math::Vector4i>({ 720, 1280, 1561, 12 }, { 800, 600, 654, 53 });
	test_vector_i<ecm::math::Vector4iA>({ 720, 1280, 1561, 12 }, { 800, 600, 654, 53 });
}

void test_matrices()
{
	ecm::math::Matrix4x4 mat1{ 5, 7, 9, 10, 2, 3, 3, 8, 8, 10, 2, 3, 3, 3, 4, 8 };
	ecm::math::Matrix4x4 mat2{ 3, 10, 12, 18, 12, 1, 4, 9, 9, 10, 12, 2, 3, 12, 4, 10 };
	ecm::math::Matrix4x4 matRes = mat1 * mat2;

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
	test_vectors();
	test_matrices();

	system("pause");
	return 0;
}
