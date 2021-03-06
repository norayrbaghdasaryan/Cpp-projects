#include "UnitTests.h"
#include "AbelianGroupCalculator.h"
#include <iostream>
#include "SimsMatrix.h"
#include "EilerFunction.h"
#include "SmithNormalizer.h"
#include "Polynomial.h"
#include "Rational.h"

void Testing::testSimsAlgorithm() {
	std::cout << "Testing sims algorithm" << std::endl;
	std::cout << "Input symmetric group size" << std::endl;
	size_t n = 0;
	std::cin >> n;
	std::vector<int> vec(n);
	std::vector<Permutation> perms;
	while (std::cin >> vec[0]) {
		for (size_t i = 1; i < n; ++i) {
			std::cin >> vec[i];
		}
		perms.emplace_back(vec);
	}
	std::cin.clear();
	SimsMatrix matrix(perms);
	std::cout << matrix;
	std::cout << "Group size = " << matrix.getGroupSize() << std::endl;
	std::cout << "Input elements" << std::endl;
	while (std::cin >> vec[0]) {
		for (size_t i = 1; i < n; ++i) {
			std::cin >> vec[i];
		}
		std::cout << (matrix.isGroupMember(vec) ? "Member" : "Non member") << std::endl;
	}
	std::cin.clear();
}

void Testing::testAbelianGroupCount() {
	std::cout << "Testing abelian group count calculator" << std::endl;
	int count = 0;
	std::cout << "Input abelian group size" << std::endl;
	while (std::cin >> count) {
		std::cout << "result ";
		std::cout << AbelianGroupCalculator::getInstance().calculateCount(count) << std::endl;
	}
	std::cin.clear();
}

void Testing::testAbelianGroupIsomorphism() {
	std::cout << "Testing abelian group isomorphism" << std::endl;
	std::cout << "Input first abelian group numbers" << std::endl;
	int number = 1;
	std::vector<int> vec1, vec2;
	while (std::cin >> number) {
		vec1.push_back(number);
	}
	std::cin.clear();
	std::cout << "Input second abelian group numbers" << std::endl;
	while (std::cin >> number) {
		vec2.push_back(number);
	}
	std::cin.clear();

	std::cout << std::boolalpha << AbelianGroupCalculator::getInstance().isIsomorph(vec1, vec2) << std::endl;
}

void Testing::testEilerFunction() {
	std::cout << "Testing eiler function" << std::endl;
	int number;
	std::cout << "input number" << std::endl;
	while (std::cin >> number) {
		std::cout << "result " << EilerFunction::getInstance().calculate(number) << std::endl;
	}
	std::cin.clear();
}

void Testing::testSmithNormalizer() {
	size_t matrix_size = 0;
	std::cout << "Testing Smith normalizer" << std::endl;
	std::cout << "Input matrix size ";
	std::cin >> matrix_size;
	std::cout << std::endl << "Input matrix elements" << std::endl;;
	std::vector<std::vector<Polynomial<Rational>>> matrix(matrix_size, std::vector<Polynomial<Rational>>(matrix_size));
	for (size_t i = 0; i < matrix_size; ++i) {
		Rational minus_one(-1);
		Rational r;
		for (size_t j = 0; j < matrix_size; ++j) {
			std::cin >> r;
			matrix[i][j] = (i == j ? Polynomial<Rational>({ {0, r}, {1, minus_one} }) : r);
		}
	}
	SmithNormalizer<Rational> s(matrix);
	std::cout << s << std::endl;
}