/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:30:35 by makurz            #+#    #+#             */
/*   Updated: 2023/09/09 11:28:53 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string to_upper(std::string str)
{
  std::string::iterator   it;

  for (it = str.begin(); it != str.end(); it++) {
    *it = std::toupper(static_cast<unsigned char>(*it));
  }
  return str;
}

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  }
  else {
    for (int i = 1; i < argc; i++) {
      ++argv;
      std::cout << to_upper(*argv);
    }
  }
  std::cout << std::endl;
  return 0;
}
