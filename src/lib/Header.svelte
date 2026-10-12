<script>
    export let name;
    // false on pages that provide their own <h1>
    export let heading = true;
</script>

<div class="header">
    <div>
        <svelte:element this={heading ? "h1" : "p"} class="title is-1 is-size-3-mobile" style="text-align: center;">
            Grundlagen: Rechnerarchitektur
        </svelte:element>
        <p class="subtitle is-3 is-size-5-mobile" style="text-align: center;">
            Sommersemester 2024 | {name}
        </p>
    </div>
</div>

<style>

    .header {
        margin-top: 5em;
        margin-bottom: 5em;
    }
</style>
