/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VFS.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:02:50 by zel-bouz          #+#    #+#             */
/*   Updated: 2024/02/04 16:47:18 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VFS.hpp"

File::File( void ) {
}

File::File( const std::string& data) {
}

const std::string&	File::read( void ) {
	return data;
}

Dir::Dir( void ) {
}

Dir::Dir( const std::string& fileName, const std::string& data ) {
	if (files.find( fileName ) != files.end())
		throw std::runtime_error("File already exist");
	files[fileName] = new File( data );
}

void	Dir::mkdir( const std::string& dirname ) {
	if (dirs.find( dirname ) != dirs.end())
		throw std::runtime_error("Dir already exist");
	dirs[dirname] = new Dir();
}


void	Dir::rmdir( const std::string& dirname ) {
	if (dirs.find( dirname) == dirs.end())
		throw std::runtime_error("no such directory");
	dirs.erase(dirname);
}


void	Dir::rmfile( const std::string& filename ) {
	if (files.find( filename) == files.end())
		throw std::runtime_error("no such file");
	files.erase( filename );
}

Dir::Items	Dir::readDir( void ) {
	Items	items;

	for ( auto it : files ) {
		items.first.push_back( it.first );
	}

	for ( auto it : dirs ) {
		items.second.push_back( it.first );
	}
	return items;
}
