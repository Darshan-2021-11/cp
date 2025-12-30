#include <bits/stdc++.h>
using namespace std;

/*{{{ nor's fastio: https://judge.yosupo.jp/submission/75233*/
struct IOPre {
	static constexpr int TEN = 10, SZ = TEN * TEN * TEN * TEN;
	std::array<char, 4 * SZ> num;
	constexpr IOPre() : num{} {
		for (int i = 0; i < SZ; i++) {
			int n = i;
			for (int j = 3; ~j; j--) {
				num[i * 4 + j] = static_cast<char>(n % TEN + '0');
				n /= TEN;
			}
		}
	}
};
struct IO {
	static constexpr int SZ = 1 << 17, LEN = 32, TEN = 10, HUNDRED = TEN * TEN,
									 THOUSAND = HUNDRED * TEN, TENTHOUSAND = THOUSAND * TEN,
									 MAGIC_MULTIPLY = 205, MAGIC_SHIFT = 11, MASK = 15,
									 TWELVE = 12, SIXTEEN = 16;
	static constexpr IOPre io_pre = {};
	std::array<char, SZ> input_buffer, output_buffer;
	int input_ptr_left, input_ptr_right, output_ptr_right;
	bool empty;

	IO() :
		input_buffer{},
		output_buffer{},
		input_ptr_left{},
		input_ptr_right{},
		output_ptr_right{},
		empty{} {}
	IO(const IO&) = delete;
	IO(IO&&) = delete;
	IO& operator=(const IO&) = delete;
	IO& operator=(IO&&) = delete;

	~IO() { flush(); }

	template <class T>
		struct is_char {
			static constexpr bool value = std::is_same_v<T, char>;
		};

	template <class T>
		struct is_bool {
			static constexpr bool value = std::is_same_v<T, bool>;
		};

	template <class T>
		struct is_string {
			static constexpr bool value =
				std::is_same_v<T, std::string> || std::is_same_v<T, const char*> ||
				std::is_same_v<T, char*> || std::is_same_v<std::decay_t<T>, char*>;
			;
		};

	template <class T, class D = void>
		struct is_custom {
			static constexpr bool value = false;
		};

	template <class T>
		struct is_custom<T, std::void_t<typename T::internal_value_type>> {
			static constexpr bool value = true;
		};

	template <class T>
		struct is_default {
			static constexpr bool value = is_char<T>::value || is_bool<T>::value ||
				is_string<T>::value ||
				std::is_integral_v<T>;
		};

	template <class T, class D = void>
		struct is_iterable {
			static constexpr bool value = false;
		};

	template <class T>
		struct is_iterable<
		T, typename std::void_t<decltype(std::begin(std::declval<T>()))>> {
			static constexpr bool value = true;
		};

	template <class T, class D = void, class E = void>
		struct is_applyable {
			static constexpr bool value = false;
		};

	template <class T>
		struct is_applyable<T, std::void_t<typename std::tuple_size<T>::type>,
		std::void_t<decltype(std::get<0>(std::declval<T>()))>> {
			static constexpr bool value = true;
		};

	template <class T>
		static constexpr bool needs_newline = (is_iterable<T>::value ||
				is_applyable<T>::value) &&
		(!is_default<T>::value);

	template <typename T, typename U>
		struct any_needs_newline {
			static constexpr bool value = false;
		};
	template <typename T>
		struct any_needs_newline<T, std::index_sequence<>> {
			static constexpr bool value = false;
		};
	template <typename T, std::size_t I, std::size_t... Is>
		struct any_needs_newline<T, std::index_sequence<I, Is...>> {
			static constexpr bool value =
				needs_newline<decltype(std::get<I>(std::declval<T>()))> ||
				any_needs_newline<T, std::index_sequence<Is...>>::value;
		};

	inline void load() {
		if (empty) return;
		memmove(std::begin(input_buffer),
				std::begin(input_buffer) + input_ptr_left,
				input_ptr_right - input_ptr_left);
#if !defined(HAVE_DECL_FREAD_UNLOCKED) || !HAVE_DECL_FREAD_UNLOCKED
#define fread_unlocked fread
#endif
		input_ptr_right =
			input_ptr_right - input_ptr_left +
			static_cast<int>(fread_unlocked(
						std::begin(input_buffer) + input_ptr_right - input_ptr_left, 1,
						SZ - input_ptr_right + input_ptr_left, stdin));
#if !defined(HAVE_DECL_FREAD_UNLOCKED) || !HAVE_DECL_FREAD_UNLOCKED
#undef fread_unlocked
#endif
		input_ptr_left = 0;
		empty = input_ptr_right != SZ;
	}

	inline void read_char(char& c) {
		if (input_ptr_left + LEN > input_ptr_right) load();
		c = input_buffer[input_ptr_left++];
	}
	inline void read_string(std::string& x) {
		char c;
		while (read_char(c), c < '!') continue;
		x = c;
		while (read_char(c), c >= '!') x += c;
	}
	inline void read_string(char* x) {
		while (read_char(*x), *x < '!') continue;
		++x;
		while (read_char(*x), *x >= '!') ++x;
		*x = '\0';
	}
	template <class T>
		inline std::enable_if_t<std::is_integral_v<T>, void> read_int(T& x) {
			if (input_ptr_left + LEN > input_ptr_right) load();
			char c = 0;
			do c = input_buffer[input_ptr_left++];
			while (c < '-');
			bool minus = false;
			if (c == '-') minus = true, c = input_buffer[input_ptr_left++];
			x = 0;
			while (c >= '0')
				x = x * TEN + (c & MASK), c = input_buffer[input_ptr_left++];
			if (minus) x = -x;
		}

	inline void skip_space() {
		if (input_ptr_left + LEN > input_ptr_right) load();
		while (input_buffer[input_ptr_left] <= ' ') input_ptr_left++;
	}

	inline void flush() {
#if !defined(HAVE_DECL_FWRITE_UNLOCKED) || !HAVE_DECL_FWRITE_UNLOCKED
#define fwrite_unlocked fwrite
#endif
		fwrite_unlocked(std::begin(output_buffer), 1, output_ptr_right, stdout);
#if !defined(HAVE_DECL_FWRITE_UNLOCKED) || !HAVE_DECL_FWRITE_UNLOCKED
#undef fwrite_unlocked
#endif
		output_ptr_right = 0;
	}

	inline void write_char(char c) {
		if (output_ptr_right > SZ - LEN) flush();
		output_buffer[output_ptr_right++] = c;
	}

	inline void write_bool(bool b) {
		if (output_ptr_right > SZ - LEN) flush();
		output_buffer[output_ptr_right++] = b ? '1' : '0';
	}

	inline void write_string(const std::string& s) {
		for (auto x : s) write_char(x);
	}

	inline void write_string(const char* s) {
		while (*s) write_char(*s++);
	}

	inline void write_string(char* s) {
		while (*s) write_char(*s++);
	}

	template <typename T>
		inline std::enable_if_t<std::is_integral_v<T>, void> write_int(T x) {
			if (output_ptr_right > SZ - LEN) flush();
			if (!x) {
				output_buffer[output_ptr_right++] = '0';
				return;
			}
			if constexpr (std::is_signed<T>::value == true)
				if (x < 0) output_buffer[output_ptr_right++] = '-', x = -x;
			int i = TWELVE;
			std::array<char, SIXTEEN> buf{};
			while (x >= TENTHOUSAND) {
				memcpy(std::begin(buf) + i,
						std::begin(io_pre.num) + (x % TENTHOUSAND) * 4, 4);
				x /= TENTHOUSAND;
				i -= 4;
			}
			if (x < HUNDRED) {
				if (x < TEN) {
					output_buffer[output_ptr_right++] = static_cast<char>('0' + x);
				} else {
					std::uint32_t q =
						(static_cast<std::uint32_t>(x) * MAGIC_MULTIPLY) >>
						MAGIC_SHIFT;
					std::uint32_t r = static_cast<std::uint32_t>(x) - q * TEN;
					output_buffer[output_ptr_right] = static_cast<char>('0' + q);
					output_buffer[output_ptr_right + 1] =
						static_cast<char>('0' + r);
					output_ptr_right += 2;
				}
			} else {
				if (x < THOUSAND) {
					memcpy(std::begin(output_buffer) + output_ptr_right,
							std::begin(io_pre.num) + (x << 2) + 1, 3),
						output_ptr_right += 3;
				} else {
					memcpy(std::begin(output_buffer) + output_ptr_right,
							std::begin(io_pre.num) + (x << 2), 4),
						output_ptr_right += 4;
				}
			}
			memcpy(std::begin(output_buffer) + output_ptr_right,
					std::begin(buf) + i + 4, TWELVE - i);
			output_ptr_right += TWELVE - i;
		}
	template <typename T_>
		IO& operator<<(T_&& x) {
			using T = typename std::remove_cv<
				typename std::remove_reference<T_>::type>::type;
			static_assert(is_custom<T>::value or is_default<T>::value or
					is_iterable<T>::value or is_applyable<T>::value);
			if constexpr (is_custom<T>::value) {
				write_int(x.get());
			} else if constexpr (is_default<T>::value) {
				if constexpr (is_bool<T>::value) {
					write_bool(x);
				} else if constexpr (is_string<T>::value) {
					write_string(x);
				} else if constexpr (is_char<T>::value) {
					write_char(x);
				} else if constexpr (std::is_integral_v<T>) {
					write_int(x);
				}
			} else if constexpr (is_iterable<T>::value) {
				// strings are immune
				using E = decltype(*std::begin(x));
				constexpr char sep = needs_newline<E> ? '\n' : ' ';
				int i = 0;
				for (const auto& y : x) {
					if (i++) write_char(sep);
					operator<<(y);
				}
			} else if constexpr (is_applyable<T>::value) {
				// strings are immune
				constexpr char sep =
					(any_needs_newline<
					 T, std::make_index_sequence<std::tuple_size_v<T>>>::value)
					? '\n'
					: ' ';
				int i = 0;
				std::apply(
						[this, &sep, &i](auto const&... y) {
						(((i++ ? write_char(sep) : void()), this->operator<<(y)),
						 ...);
						},
						x);
			}
			return *this;
		}
	template <typename T>
		IO& operator>>(T& x) {
			static_assert(is_custom<T>::value or is_default<T>::value or
					is_iterable<T>::value or is_applyable<T>::value);
			static_assert(!is_bool<T>::value);
			if constexpr (is_custom<T>::value) {
				typename T::internal_value_type y;
				read_int(y);
				x = y;
			} else if constexpr (is_default<T>::value) {
				if constexpr (is_string<T>::value) {
					read_string(x);
				} else if constexpr (is_char<T>::value) {
					read_char(x);
				} else if constexpr (std::is_integral_v<T>) {
					read_int(x);
				}
			} else if constexpr (is_iterable<T>::value) {
				for (auto& y : x) operator>>(y);
			} else if constexpr (is_applyable<T>::value) {
				std::apply([this](auto&... y) { ((this->operator>>(y)), ...); }, x);
			}
			return *this;
		}

	IO* tie(std::nullptr_t) { return this; }
	void sync_with_stdio(bool) {}
};
IO io;
#define cin io
#define cout io
/* nor's fastio }}} */

uint64_t sum(uint64_t N)
{ 
	uint64_t sum = 0;
	uint64_t i,temp;
	for(i =1;i<=N;i++)
	{
		temp = i;
		while(temp != 0)
		{
			//extracting last digit and adding to sum
			sum = sum + temp%10;
			//removing digit
			temp = temp/10;
		}
	}
	return sum;
}
int64_t a[100000];

void calculate_sum(int d) 
{
	a[0] = 0;
	a[1] = 45;
	for(int i=2;i<=d;i++)
	{
		//sum(10^d - 1) = sum((10^d-1)-1)*10 + 45 * 10^(d-1)
		a[i] = a[i-1]*10 + 45*pow(10,i-1);
	}
}

long long sum_of_digits(long long N)
{
	//base condition
	//if N less than 10
	//return sum of first N numbers
	if (N<10) 
		return N*(N+1)/2;

	//calculating number of digits in N   	
	long long d = log10(N);

	//calculate sum of digits from 1 to 10^d-1
	calculate_sum(d);

	//left most digit
	long long lmd = N/pow(10,d);

	//store the value of 10^d
	long long t = ceil(pow(10,d));

	return lmd * a[d] + (lmd*(lmd-1)/2) * t + lmd * (1 + N % t) + sum_of_digits(N % t); 
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	uint64_t value[19] = {
		0ULL,
		9ULL,
		189ULL,
		2889ULL,
		38889ULL,
		488889ULL,
		5888889ULL,
		68888889ULL,
		788888889ULL,
		8888888889ULL,
		98888888889ULL,
		1088888888889ULL,
		11888888888889ULL,
		128888888888889ULL,
		1388888888888889ULL,
		14888888888888889ULL,
		158888888888888889ULL,
		1688888888888888889ULL,
		17888888888888888889ULL,
	};
	uint64_t l[20] = {
		0ULL,
		9ULL,
		99ULL,
		999ULL,
		9999ULL,
		99999ULL,
		999999ULL,
		9999999ULL,
		99999999ULL,
		999999999ULL,
		9999999999ULL,
		99999999999ULL,
		999999999999ULL,
		9999999999999ULL,
		99999999999999ULL,
		999999999999999ULL,
		9999999999999999ULL,
		99999999999999999ULL,
		999999999999999999ULL,
		9999999999999999999ULL,
	};

	uint64_t TC = 1, k, t, u, ans, dgt, tmp;
	char b[22];
	cin >> TC;
	while (TC--) {
		cin >> k;
		t = 18;
		while (k <= value[t])
			--t;
		k -= value[t];
		++t;
		u = k % t;
		// number at that position
		k = l[t - 1] + (k / t);
		ans = sum_of_digits(k);
		if (u != 0) {
			++k;
			sprintf(b, "%llu", (long long unsigned int)k);
			dgt = 0;
			tmp = k;
			while (tmp) {
				++dgt;
				tmp /= 10;
			}
			for (uint64_t i = 0; i < u; ++i) ans += b[i] - '0';
		}
		cout << ans << '\n';
	}
}
