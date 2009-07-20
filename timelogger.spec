Summary: Time Logger software
Name: timelogger
Version: 0.6.0
Release: 5
Source0: %{name}-%{version}.tar.gz
License: GPL v2
URL: http://etm.leonti.ru
Group: Utilities
BuildRoot: %{_builddir}/%{name}-root
%description
Time Logger - software to track employee working time.
Part of ETM project.
Use with ETM Manager 0.6.0 or later
%prep
%setup -q
%build
./configure
make
%install
rm -rf $RPM_BUILD_ROOT
make DESTDIR=$RPM_BUILD_ROOT install
%clean
rm -rf $RPM_BUILD_ROOT
%files
%defattr(-,root,root)
/usr/local/bin/*
%changelog
* Sat Apr 12 2008 Leonti Bielski <prishelec@gmail.com> 0.6.0
- New database scheme is used so it's not compatible with ETM php scripts
Use it with ETM Manager
- Program interface changed to be more suitable for touchscreens
(preferable use)
* Sun Jan 20 2008 Leonti Bielski <prishelec@gmail.com> 0.5.0
- First public release of Time Logger