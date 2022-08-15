#ifndef _HTTPCACH_H_
#define _HTTPCACH_H_

//
// key and data for uri-cache
//

#define URI_CACHE_NAME             L"URI"

class IUriKey : public IHttpCacheKey
{
 public:
    PCWSTR
    GetCacheName(
        VOID
    ) const
    {
        return URI_CACHE_NAME;
    }

    virtual
    PCWSTR
    GetUrl(
        VOID
    ) const = 0;

    virtual
    PCWSTR
    GetSiteName(
        VOID
    ) const = 0;

    virtual
    DWORD
    GetSiteId(
        VOID
    ) const = 0;
};

//
// key and data for file-cache
//

#define FILE_CACHE_NAME             L"FILE"

class IFileKey : public IHttpCacheKey
{
public:
    PCWSTR
    GetCacheName(
        VOID
    ) const
    {
        return FILE_CACHE_NAME;
    }

    virtual
    PCWSTR
    GetPath(
        VOID
    ) const = 0;
};

//
// key and data for token-cache
//

#define TOKEN_CACHE_NAME            L"TOKEN"

class IHttpTokenKey : public IHttpCacheKey
{
 public:
    PCWSTR
    GetCacheName(
        VOID
    ) const
    {
        return TOKEN_CACHE_NAME;
    }

    virtual
    PCWSTR
    GetUserName(
        VOID
    ) const = 0;

    virtual
    PCWSTR
    GetPasswordHash(
        VOID
    ) const = 0;

    //
    // return the LOGON32_LOGON_* method used when logging on the user
    //
    
    virtual
    DWORD
    GetLogonMethod(
        VOID
    ) const = 0;
};

#endif


