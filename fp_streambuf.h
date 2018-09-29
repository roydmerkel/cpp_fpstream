#ifndef FP_STREAMBUF_H
#define FP_STREAMBUF_H

#include <streambuf>
#include <cstdio>

class fp_streambuf : public std::streambuf
{
public:
	// member types
	typedef std::streambuf::char_type char_type;
	typedef std::streambuf::traits_type traits_type;
	typedef std::streambuf::int_type int_type;
	typedef std::streambuf::pos_type pos_type;
	typedef std::streambuf::off_type off_type;

	// member functions
	virtual ~fp_streambuf();
	fp_streambuf(FILE* fp);
	fp_streambuf(const fp_streambuf& rhs);

	// locales
	std::locale pubimbue( const std::locale& loc );
	std::locale getloc() const;

	// positioning
	std::streambuf* pubsetbuf( char_type* s, std::streamsize n );
	pos_type pubseekoff( off_type off, std::ios_base::seekdir dir, std::ios_base::openmode which = std::ios_base::in | std::ios_base::out );
	pos_type pubseekpos( pos_type pos, std::ios_base::openmode which = std::ios_base::in | std::ios_base::out );
	int pubsync();

	// get area
	std::streamsize in_avail();
	int_type snextc();
	int_type sbumpc();
	void stossc();
	int_type sgetc();
	std::streamsize sgetn( char_type* s, std::streamsize count );

	// put area
	int_type sputc( char_type ch );
	std::streamsize sputn( const char_type* s, std::streamsize count );

	// putback
	int_type sputbackc( char_type c );
	int_type sungetc();
protected:
	// locales
	virtual void imbue( const std::locale& loc );

	// positioning
	virtual std::streambuf* setbuf( char_type* s, std::streamsize n );
	virtual pos_type seekoff( off_type off, std::ios_base::seekdir dir, std::ios_base::openmode which = std::ios_base::in | std::ios_base::out );
	virtual pos_type seekpos( pos_type pos, std::ios_base::openmode which = std::ios_base::in | std::ios_base::out);
	virtual int sync();

	// get area
	virtual std::streamsize xsgetn( char_type* s, std::streamsize count );
	virtual std::streamsize showmanyc();
	virtual int_type underflow();
	virtual int_type uflow();
	char_type* eback() const;
	char_type* gptr() const;
	char_type* egptr() const;
	void gbump( int count );
	void setg( char_type* gbeg, char_type* gcurr, char_type* gend );

	// put area
	virtual std::streamsize xsputn( const char_type* s, std::streamsize count );
	virtual int_type overflow( int_type ch = traits_type::eof() );
	char_type* pbase() const;
	char_type* pptr() const;
	char_type* epptr() const;
	void pbump( int count );
	void setp( char_type* pbeg, char_type* pend );

	// putback
	virtual int_type pbackfail( int_type c = traits_type::eof() );

	// protected member functions
	fp_streambuf& operator=( const fp_streambuf& other );
	void swap( fp_streambuf& other );
private:
};

#endif // #define FP_STREAMBUF_H
