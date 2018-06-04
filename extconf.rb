require 'mkmf'

if /linux/ =~ RUBY_PLATFORM
  puts "On Linux"
  $CPPFLAGS << " -I/usr/include/gdal"
  $LDFLAGS << " -L/usr/lib"
  have_library("CGAL_Core")
  have_library("gmp")
  have_library("mpfr")
  have_library('CGAL')
  have_library('gdal')
  have_library('boost_program_options')
  have_library('boost_thread')
  have_library('boost_system')
  have_library('boost_chrono')
  have_library('boost_date_time')
  have_library('boost_atomic')
  have_library('boost_thread')
  have_library('boost_chrono')
  have_library('boost_system')
  have_library('boost_date_time')
  have_library('boost_atomic')
  have_header('/usr/include/gdal/ogrsf_frmts.h')
end

if /darwin/ =~ RUBY_PLATFORM
  puts "On OSX"
  have_library("CGAL_Core")
  have_library("gmp")
  have_library("mpfr")
  have_library('CGAL')
  have_library('gdal')
  have_library('boost_program_options-mt')
  have_library('boost_thread-mt')
  have_library('boost_system-mt')
  have_library('boost_chrono-mt')
  have_library('boost_date_time-mt')
  have_library('boost_atomic-mt')
  have_library('boost_thread-mt')
  have_library('boost_chrono-mt')
  have_library('boost_system-mt')
  have_library('boost_date_time-mt')
  have_library('boost_atomic-mt')
end

create_makefile('prepair')
