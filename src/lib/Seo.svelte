<script>
    import { SITE_URL, SITE_NAME } from "$lib/site.js";

    export let title;
    export let description;
    // path relative to SITE_URL, e.g. "" or "ssh"
    export let path = "";
    export let type = "website";
    /** @type {object | null} */
    export let jsonld = null;

    const url = SITE_URL + path;
</script>

<svelte:head>
    <title>{title}</title>
    <meta name="description" content={description} />
    <link rel="canonical" href={url} />

    <meta property="og:type" content={type} />
    <meta property="og:site_name" content={SITE_NAME} />
    <meta property="og:locale" content="de_DE" />
    <meta property="og:title" content={title} />
    <meta property="og:description" content={description} />
    <meta property="og:url" content={url} />
    <meta name="twitter:card" content="summary" />

    {#if jsonld}
        {@html `<script type="application/ld+json">${JSON.stringify(jsonld)}</` + `script>`}
    {/if}
</svelte:head>
