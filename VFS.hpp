/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VFS.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:52:44 by zel-bouz          #+#    #+#             */
/*   Updated: 2024/02/04 16:47:03 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <utility>


// touch		=> create a file
// mkdir		=> create a dirname in the current dir
// cd / chdir	=> change the
// cwd			=> return current dir
// rmdir		=> removes a dir
// rm 			=> removes a file
// read			=> reads a file

class	File {
	private:
		std::string	data;
	public:
		File( void );
		File( const std::string& data );
		const std::string&	read( void );
};



class	Dir {
	private:
		std::map<std::string, File*>	files;
		std::map<std::string, Dir*>		dirs;
	public:
		typedef	std::pair<std::vector<std::string>, std::vector<std::string>>	Items;
		Dir( void );
		Dir( const std::string& fileName, const std::string& data );
		void	mkdir( const std::string& dirname );
		void	rmdir( const std::string& dirname );
		void	rmfile( const std::string& filename );
		Items	readDir( void );
};


class	VFS {
	private:
		Dir*	root;
		Dir*	currDir;
		std::stack<std::string>	path;
	public:
		VFS( void );
};
